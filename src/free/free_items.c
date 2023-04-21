/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** free_items
*/

#include "rpg.h"

void free_items(rpg_t *rpg)
{
    item_e **items = rpg->items;
    item_e *prev = NULL;

    for (item_e *node = *items; node;) {
        prev = node;
        node = node->next;
        *items = node;
        free(prev);
    }
}
