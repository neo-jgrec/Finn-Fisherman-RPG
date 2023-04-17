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
        set_sprite(node, rpg);
        sfRenderWindow_drawSprite(rpg->win->win,
            node->sp, NULL);
    }
}
