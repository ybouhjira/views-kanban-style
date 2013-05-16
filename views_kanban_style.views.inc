<?php

/**
 * @file views_kanban_style.views.inc
 */
function views_kanban_style_views_plugins() {
    return array(
        'module' => 'views_kanban_style',
        'style' => array(
            'kanban' => array(
                'title' => t('Kanban'),
                'theme' => 'views_view_kanban',
                'no ui' => FALSE,
                'handler' => 'views_kanban_style_plugin_style_kanban',
                'uses row plugin' => FALSE,
                'uses fields' => TRUE,
                'uses options' => TRUE,
                'type' => 'normal',
                'uses grouping' => TRUE,
            )
        )
    );
}