/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** add_item
*/

#include "rpg.h"

static void default_item(item_e *item, int nb, VEC pos)
{
    item->item_number = nb;
    item->equiped = 0;
    item->in_inventory = 1;
    item->item_stat = (player_stat_t){0};
    item->item_stat.jump = 0;
    item->sprite = 0;
    item->type = 0;
    item->pos = pos;
    item->desc = "null item";
    item->next = NULL;
    return;
}

void add_item(rpg_t *rpg, int nb, VEC pos)
{
    data_t *data = rpg->data;
    item_e **items = rpg->items;
    item_e *item = malloc(sizeof(item_e));

    if (nb >= data->nb_item)
        return default_item(item, nb, pos);
    item->item_number = nb;
    item->equiped = 0;
    item->in_inventory = 0;
    item->item_stat = data->item_list[nb].item_stat;
    item->sprite = data->item_list[nb].sprite;
    item->type = data->item_list[nb].type;
    item->pos = pos;
    item->desc = data->item_list[nb].desc;
    item->next = *items;
    *items = item;
}
