select 
    ii.item_id,
    ii.item_name,
    ii.rarity
from 
    item_info as ii 
    inner join item_tree as it 
        on ii.item_id = it.item_id 
where it.parent_item_id in (select item_id from item_info where rarity = 'RARE')
order by 
    it.item_id desc;