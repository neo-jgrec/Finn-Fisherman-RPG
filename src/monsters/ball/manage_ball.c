/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_skeleton
*/

#include "rpg.h"

static void set_position_ball(win_t *win,
    entity_t *player, rpg_t *rpg)
{
    sfFloatRect rect = {0};

    move_player(player, (VEC){player->dir * win->deltaT *
            500, 0});
    if (sfFloatRect_intersects(&player->rect, &rpg->player->rect, &rect)) {
        hit_player(rpg, player->damage / 2, rpg->player);
        set_death(rpg, player);
    }
}

void set_var_ball(entity_t *monster, rpg_t *rpg)
{
    monster->time += rpg->win->deltaT;
    if (monster->health.health == 0)
        return;
    set_position_ball(rpg->win, monster, rpg);
}
