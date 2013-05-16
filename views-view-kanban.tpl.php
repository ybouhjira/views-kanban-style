
<? $index = 0; ?>
<ul class="views-kanban-column">
    <a href="#" class="button-fold button" title="fold"><<</a>
    <h2><? echo $title; ?> </h2>
    <? foreach ($rows as $key => $row) : ?>
        <li class="views-kanban-card">
            <? foreach ($row as $key => $field) : ?>
                <? echo $row->{$key}; ?><br/>
            <? endforeach; ?>
        </li>
    <? endforeach; ?>
</ul>

<script>
    (function($) {
        Drupal.behaviors.views_kanban_style = {
            attach: function() {
                var maxHeight = 0;
                var cols = $('.views-kanban-column').each(function() {
                    var h = $(this).outerHeight(true);
                    console.log(h);
                    if (h > maxHeight)
                        maxHeight = h;
                });
                cols.css('height', maxHeight + 'px');
                $(cols[0]).closest('.views-kanban').css({
                    'height': (maxHeight + 20) + 'px',
                });
            }
        };
    })(jQuery);
</script>