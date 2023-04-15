/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_position
*/

#include "rpg.h"

void set_position(win_t *win, entity_t *player, rpg_t *rpg)
{
    player->velocity += 2500 * win->deltaT;

    move_player(player, (VEC){0, 1 * win->deltaT * player->velocity});
    check_collision(player, rpg->puzzle, 0);
    if (((player->state == HIT || player->state == ATTACK) &&
        player->grounded))
        return;
    if (player->state != ROLL)
        move_player(player, (VEC){player->hor * win->deltaT *
            rpg->data->speed, 0});
    else
        move_player(player,
            (VEC){player->roll.save_dir * win->deltaT * 800, 0});
    check_collision(player, rpg->puzzle, 1);
}
