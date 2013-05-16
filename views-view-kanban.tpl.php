
<div class="views-kanban-column-wrapper"><a href="#" class="button-fold button" title="fold"><<</a>
    <h2><? echo $title; ?> </h2>
<ul class="views-kanban-column views-col-<?echo $view->name;?>">
    <? foreach ($rows as $key => $row) : ?>
        <li class="views-kanban-card">
            <? foreach ($row as $key => $field) : ?>
                <? echo $row->{$key}; ?><br/>
            <? endforeach; ?>
        </li>
    <? endforeach; ?>
</ul></div>

<script>
    
</script>