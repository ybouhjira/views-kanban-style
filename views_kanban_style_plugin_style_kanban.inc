<?php

/**
 * @file views_kaban_style_plugin_style_kanban.inc
 */
class views_kanban_style_plugin_style_kanban extends views_plugin_style {

    function render_grouping_sets($sets, $level = 0) {
        $output = '';

        // copy pasted from here: 
        // http://api.drupal.org/api/views/plugins!views_plugin_style.inc/function/views_plugin_style%3A%3Arender_grouping_sets/7
        $index = 0;
        foreach ($sets as $key => $set) {
            $output .= theme($this->theme_functions(), array(
                'view' => $this->view,
                'options' => $this->options,
                'grouping_level' => $level,
                'rows' => $set['rows'],
                'title' => $set['group'],
                'column' => $index++,
            ));
        }
        unset($this->view->row_index);

        // Add gridster HTML markup
        drupal_add_js('system', 'ui.draggable');
        drupal_add_js('system', 'ui.sortable');
        drupal_add_js(drupal_get_path('module', 'views_kanban_style') . '/kanban.js');
        drupal_add_css(drupal_get_path('module', 'views_kanban_style') . '/kanban.css');
        return "<div class='views-kanban'>$output</div>";
    }

}