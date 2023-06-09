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
        if (node->id == SHROOM)
            set_sprite_shroom(node, rpg);
        if (node->id == TROLL)
            set_sprite_troll(node, rpg);
        if (node->id == BALL)
            set_sprite_ball(node, rpg);
        if (node->id == SLASH)
            set_sprite_slash(node, rpg);
        sfRenderWindow_drawSprite(rpg->win->win,
            node->sp, NULL);
    }
}
