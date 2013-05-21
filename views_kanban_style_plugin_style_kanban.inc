<?php

/**
 * @file views_kaban_style_plugin_style_kanban.inc
 */
class views_kanban_style_plugin_style_kanban extends views_plugin_style {

    /**
     * Defines custom options 
     */
    function option_definition() {
        $options = parent::option_definition();
        $options['values'] = array('default' => '');
        return $options;
    }

    /**
     * Options configuration form
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
        $form['values'] = array(
            '#title' => 'Values',
            '#type' => 'textfield',
            '#default_value' => $this->options['values'],
            '#description' => t('The values to use as columns headers (semicolon separated)'),
        );
    }

    function render_grouping_sets($sets, $level = 0) {
        $output = '';

        // REORDRING THE SETS ACCORDING TO THE VALUES OPTION
        $new_sets = array();
        $values_option = explode(';', $this->options['values']);

        // $values_options should not be empty if
        // the user have filled the field in the style options                         
        if (!empty($values_option)) {
            // We move the values that have results in $sets to $new_sets

            foreach ($values_option as $option) {
                if (array_key_exists($option, $sets)) {
                    $new_sets[$option] = $sets[$option];
                    unset($sets[$option]);
                } else {
                    $new_sets[$option] = array(
                        'group' => $option,
                        'rows' => array()
                    );
                }
            }
            // then add the others with array_merge
            array_merge($new_sets, $sets);
        }

        $index = 0;
        $offset = 0;
        $grouping_field = $this->options['grouping'][0]['field'];
        //$grouping_field_alias = $this->view->field[$grouping_field]->field_alias;
        foreach ($new_sets as $set) {
            $output .= theme($this->theme_functions(), array(
                'view' => $this->view,
                'options' => $this->options,
                'grouping_level' => $level,
                'rows' => $set['rows'],
                'title' => $set['group'],
                'column' => $index++,
                'rendered_rows' => array_slice($this->rendered_fields, $offset, count($set['rows'])),
            ));
            $offset += count($set['rows']);
        }
        unset($this->view->row_index);

        // Adding jQueryUI components
        drupal_add_library('system', 'ui.draggable');
        drupal_add_library('system', 'ui.sortable');
        drupal_add_library('system', 'ui.droppable');
        // The javascript & css for the style
        drupal_add_js(drupal_get_path('module', 'views_kanban_style') . '/kanban.js');
        drupal_add_css(drupal_get_path('module', 'views_kanban_style') . '/kanban.css');
        // We wrap the groups in a div.views-kanban
        return "<div class='views-kanban' data-grouping-field='$grouping_field'>$output</div>";
    }

}