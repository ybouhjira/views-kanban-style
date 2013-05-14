<table>
    <? foreach ($this->view->result as $node) : ?>
        <tr>
            <td><? echo $node->node_title ?></td>
            <td><? echo $node->nid ?></td>
            <td><? echo $node->node_created ?></td>
        </tr>
    <? endforeach; ?>
</table>