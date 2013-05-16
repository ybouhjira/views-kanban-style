
<? $index = 0; ?>
<? foreach ($rows as $key => $row) : ?>
    <li data-row="<? echo $index++ + 1; ?>" data-col="<? echo $column + 1; ?>" data-sizex="1" data-sizey="1">
        <? echo ($column + 1) . ' | ' .($index); ?>
    </li>
<? endforeach; ?>