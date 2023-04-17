/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_monsters
*/

#include "rpg.h"

void draw_monsters(rpg_t *rpg)
{
    entity_t **monsters = rpg->monsters;

    for (entity_t *node = *monsters; node; node = node->next) {
        if (node->id == SKELETON)
            set_sprite_skeleton(node, rpg);
        if (node->id == EYE)
            set_sprite_eye(node, rpg);
        sfRenderWindow_drawSprite(rpg->win->win,
            node->sp, NULL);
    }
}
