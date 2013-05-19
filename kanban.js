(function($) {
    /**
     * giv the same height to the Kanban's columns
     */
    function same_height() {
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
    }

    /**
     * Enables sorting using jQueryUI .sortable() method
     */ 
    function enable_sorting() {
        $('.views-kanban-column').each(function() {
            // find the class views-col-<viewName>
            var classes = $(this).attr('class').split(/\s+/);
            var connect_class = '';
            for(var i=0; i<classes.length; ++i) {
                if(classes[i].match(/^views-col-/)) {
                    connect_class = classes[i];
                    break;
                }
            }
            // trigger sorting
            $(this).sortable({
                connectWith: '.' + connect_class,
                placeholder: 'views-kanban-placeholder',
                dropOnEmpty: true
            });
        });
    }

    Drupal.behaviors.views_kanban_style = {
        attach: function() {
            same_height();
            enable_sorting();
        }
    };
})(jQuery);