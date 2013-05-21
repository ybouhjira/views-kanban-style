(function($) {

    /**
     * giv the same height to the Kanban's columns
     */
//    function same_height() {
//        alert('same height');
//        var maxHeight = 0;
//        var cols = $('.views-kanban-column').each(function() {
//            var h = $(this).outerHeight(true);
//            if (h > maxHeight)
//                maxHeight = h;
//        });
//        cols.css('height', maxHeight + 'px');
//        $(cols[0]).closest('.views-kanban').css('height', (maxHeight + 20) + 'px');
//    }

    /**
     * Enables sorting using jQueryUI .sortable() method
     */
    function enable_sorting() {
        $('.views-kanban-column').each(function() {
            // find the class views-col-<viewName>
            var classes = $(this).attr('class').split(/\s+/);
            var connect_class = '';
            for (var i = 0; i < classes.length; ++i) {
                if (classes[i].match(/^views-col-/)) {
                    connect_class = classes[i];
                    break;
                }
            }
            // trigger sorting
            $(this).sortable({
                connectWith: '.' + connect_class,
                placeholder: 'views-kanban-placeholder',
                dropOnEmpty: true
                //stop: same_height
            });
        });
    }

    /**
     * Enables columns folding
     */
    function enable_column_folding() {
        $('.button-fold').click(function() {
            var wrapper = $(this).closest('.views-kanban-column-wrapper');
            wrapper.find('h2').toggleClass('rotated-column-title');
            wrapper.find('ul').toggle('slow');
            return false;
        });
    }

    Drupal.behaviors.views_kanban_style = {
        attach: function() {
            //same_height();
            enable_sorting();
            enable_column_folding();


            $.getJSON('views_kanban_style/update/hello', function(data) {
                alert(data);
            });
        }
    };
})(jQuery);