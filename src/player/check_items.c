/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_items
*/

#include "rpg.h"

static void pick_item(rpg_t *rpg, item_e *item)
{
    item_e **items = rpg->items;
    item_e *prev = NULL;

    if (*items == item)
        *items = item->next;
    for (item_e *node = *items; node;) {
        prev = node;
        node = node->next;
        if (node == item)
            prev->next = node->next;
    }
}

static void check_for_places(rpg_t *rpg, item_e *item)
{
    for (int i = 0; i < 9 * 3; i++) {
        if (rpg->data->inventory[i] == NULL) {
            rpg->data->inventory[i] = item;
            pick_item(rpg, item);
            item->in_inventory = 1;
            item->next = NULL;
            return;
        }
    }
}

void check_items(rpg_t *rpg)
{
    item_e **items = rpg->items;

    for (item_e *node = *items; node; node = node->next) {
        if (sfFloatRect_contains(&rpg->player->rect, node->pos.x, node->pos.y))
            check_for_places(rpg, node);
    }
}
