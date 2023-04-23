/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_skeleton
*/

#include "rpg.h"

static void set_position_slash(win_t *win,
    entity_t *player, rpg_t *rpg)
{
    sfFloatRect rect = {0};

    move_player(player, (VEC){player->dir * win->deltaT *
            500, 0});
    if (sfFloatRect_intersects(&player->rect, &rpg->player->rect, &rect) &&
        rpg->player->state != ROLL)
        hit_player(rpg, player->damage / 2, rpg->player);
}

void set_var_slash(entity_t *monster, rpg_t *rpg)
{
    if (monster->health.health == 0)
        return;
    monster->time += rpg->win->deltaT;
    set_position_slash(rpg->win, monster, rpg);
}
