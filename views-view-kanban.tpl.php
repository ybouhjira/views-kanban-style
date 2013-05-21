<div class="views-kanban-column-wrapper">
    <a href="#" class="button-fold" title="fold">
        &lt;&lt; 
    </a>
    <h2><? echo $title; ?></h2>
    <ul class="views-kanban-column views-col-<? echo $view->name; ?>">
        <? foreach ($rendered_rows as $row) : ?>
            <li class="views-kanban-card">
                <? foreach ($row as $field) : ?>
                    <? echo $field; ?><br/>
                <? endforeach; ?>
            </li>
        <? endforeach; ?>
    </ul>
</div>