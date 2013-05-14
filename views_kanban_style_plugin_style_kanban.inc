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
        $options['field'] = array('default' => '');
        return $options;
    }

    /**
     * Options configuration form
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
        $form['field'] = array(
            '#title' => 'field',
            '#type' => 'select',
            '#options' => array('field1', 'field2', 'field3'),
            '#description' => t('The field used to group the rows'),
        );
    }

    function render() {
        $output = "";
        $output .= "<table>";
        foreach ($this->view->result as $node) {
            $output .= "<tr>";
            $output .= "<td> {$node->node_title} </td>";
            $output .= "<td> {$node->nid} </td>";
            $output .= "<td> {$node->node_created} </td>";
            $output .= "</tr>";
        }
        $output .= "</table>";
        return $output;
    }

}