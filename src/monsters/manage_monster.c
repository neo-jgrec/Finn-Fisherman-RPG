/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_monster
*/

#include "rpg.h"

void manage_monster(UNUSED win_t *win, rpg_t *rpg)
{
    entity_t **monsters = rpg->monsters;

    for (entity_t *node = *monsters; node; node = node->next) {
        if (node->id == SKELETON)
            set_var_skeleton(node, rpg);
        if (node->id == EYE)
            set_var_eye(node, rpg);
        if (node->id == SHROOM)
            set_var_shroom(node, rpg);
    }
}
