/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_monsters
*/

#include "rpg.h"

static void set_anim(entity_t *monster, rpg_t *rpg)
{
    sfSprite_setPosition(monster->sp, monster->pos);
    sfRenderWindow_drawSprite(rpg->win->win, monster->sp, NULL);
}

void draw_monsters(rpg_t *rpg)
{
    entity_t **monsters = rpg->monsters;

    if (monsters == NULL)
        return;
    for (entity_t *node = *monsters; node; node = node->next) {
        manage_monster(rpg->win, node, rpg);
        set_anim(node, rpg);
        sfRenderWindow_drawSprite(rpg->win->win,
            node->sp, NULL);
    }
}
