/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** free_monsters
*/

#include "rpg.h"

void free_monsters(rpg_t *rpg)
{
    entity_t **monsters = rpg->monsters;
    entity_t *prev = NULL;

    for (entity_t *node = *monsters; node;) {
        prev = node;
        node = node->next;
        *monsters = node;
        free_entity(prev);
    }
}
