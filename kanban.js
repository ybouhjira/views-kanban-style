(function($) { //< $ = jQuery
    Drupal.behaviors.views_kanban_style = {
        attach: function() {
            $(".gridster ul").gridster({
                widget_margins: [5, 3],
                widget_base_dimensions: [140, 50]
            });
        }
    };
})(jQuery);