/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_items
*/

#include "rpg.h"

static void move_items(rpg_t *rpg, item_e *item)
{
    for (int i = 0; i < rpg->puzzle->nb_colliders; i++)
        if (sfFloatRect_contains(&rpg->puzzle->colliders[i],
            item->pos.x, item->pos.y + 16))
            return;
    item->pos.y += 100 * rpg->win->deltaT;
}

void manage_items(rpg_t *rpg)
{
    item_e **items = rpg->items;

    for (item_e *node = *items; node; node = node->next)
        move_items(rpg, node);
}
