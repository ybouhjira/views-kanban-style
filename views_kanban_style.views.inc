<?php

/**
 * @file views_kanban_style.views.inc
 */
function views_kanban_style_views_plugins() {
    drupal_set_message('views_kanban_style_views_plugins() called');
    return array(
        'module' => 'views_kanban_style',
        'style' => array(
            'kanban' => array(
                'title' => t('Kanban'),
                'no ui' => FALSE,
                'handler' => 'views_kanban_style_plugin_style_kanban',
                'uses row plugin' => FALSE,
                'uses row class' => TRUE,
                'uses fields' => TRUE,
                'uses options' => TRUE,
                'type' => 'normal',
            )
        )
    );
}