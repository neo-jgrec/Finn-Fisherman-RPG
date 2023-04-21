/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** add_item
*/

#include "rpg.h"

void add_item(rpg_t *rpg, int nb, VEC pos)
{
    item_e **items = rpg->items;
    item_e *item = malloc(sizeof(item_e));

    if (item == NULL)
        return;
    item->item_number = 5;
    item->equiped = 0;
    item->in_inventory = 0;
    item->item_stat = (player_stat_t){0};
    item->item_stat.jump = 1;
    item->sprite = 0;
    item->type = 0;
    item->pos = pos;
    item->desc = "bonjour";
    item->next = *items;
    *items = item;
}
