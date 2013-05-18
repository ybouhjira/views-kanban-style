(function($) {
    Drupal.behaviors.views_kanban_style = {
        attach: function() {
            // Same height hack
            var maxHeight = 0;
            var cols = $('.views-kanban-column-wrapper').each(function() {
                var h = $(this).outerHeight(true);
                if (h > maxHeight)
                    maxHeight = h;
            });
            cols.css('height', maxHeight + 'px');
            $(cols[0]).closest('.views-kanban').css({
                'height': (maxHeight + 20) + 'px'
            });

            // making the card draggable and sortable using jQueryUI
            $('.views-kanban-column').each(function() {
                $(this).sortable({
                    connectWith: '.' + $(this).attr('class').match(/(?=\s*)views-col-(.*)(?=\s*)/)[0],
                    placeholder: 'views-kanban-placeholder'
                });
            });
        }
    };
})(jQuery);