(function($) {

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
                dropOnEmpty: true,
                receive: function(event, ui) {
                    // triggered when a list has received an item from another list.
                    //update_node($(ui.item));
                }
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

    /**
     * sends an ajax request to update a node
     * @param {integer} nid The node's ID
     * @param {string} field The field to update
     * @param {String} value The value that will be given to the field
     */
    function update_node(nid, field, value) {
        $.getJSON('views_kanban_style/update/' + nid + '/' + field + '/' + value, function(data) {
            if (!data)
                alert('could not update node');
        });
    }

    Drupal.behaviors.views_kanban_style = {
        attach: function() {
            enable_sorting();
            enable_column_folding();


        }
    };
})(jQuery);