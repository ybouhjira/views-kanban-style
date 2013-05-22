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

    /**
     * Rendering the rows after they have been grouped
     */
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
                } else {
                    $new_sets[$option] = array('group' => $option, 'rows' => array());
                }
            }
        }

        // FINDING THE FIELDS EXCLUDED FROM DISPLAY
        $excluded_fields = array();
        foreach ($this->view->field as $field) {
            if ($field->options['exclude']) {
                array_push($excluded_fields, $field->field);
            }
        }

        // RENDERING THINGS
        foreach ($new_sets as $set) {
            // find the rendered fields
            $rendered_rows = array();
            foreach (array_keys($set['rows']) as $row_id) {
                $rendered_rows[$row_id] = $this->rendered_fields[$row_id];
            }
            
            // remove excluded fields (views ui option)
            foreach ($rendered_rows as &$rendered_row) {
                foreach ($excluded_fields as $field) {
                    unset($rendered_row[$field]);
                }
            }

            // Build an array that have node IDs as values and row_ids as keys
            // that way we the node in $rendered_rows will have the same index
            // as it's nid in $nids array
            $nids = array();
            foreach ($set['rows'] as $row_id => $row) {
                $nids[$row_id] = $row->nid;
            }

            // passe things to theme functions
            $theme_vars = array(
                'view' => $this->view,
                'rows' => $set['rows'],
                'title' => $set['group'],
                'rendered_rows' => $rendered_rows,
                'nids' => $nids,
            );
            $output .= theme($this->theme_functions(), $theme_vars);
        }
        unset($this->view->row_index);

        // CSS & JAVASCRIPT
        // Adding jQueryUI components
        drupal_add_library('system', 'ui.draggable');
        drupal_add_library('system', 'ui.sortable');
        drupal_add_library('system', 'ui.droppable');

        // The javascript & css for the style
        drupal_add_js(drupal_get_path('module', 'views_kanban_style') . '/kanban.js');
        drupal_add_css(drupal_get_path('module', 'views_kanban_style') . '/kanban.css');

        // We wrap the groups in a div.views-kanban
        $grouping_field = $this->options['grouping'][0]['field'];
        return "<div class='views-kanban' data-grouping-field='$grouping_field'>$output</div>";
    }

}