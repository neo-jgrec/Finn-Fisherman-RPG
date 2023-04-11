/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_player
*/

#include "rpg.h"

void init_player(asset_t *asset, rpg_t *rpg)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        rpg->player = NULL;
    player->state = IDLE;
    player->prev_state = IDLE;
    player->pos = (VEC){500, 700};
    player->rect = (sfFloatRect){0, 0, 64, 64};
    player->time = 0;
    set_animation(player, asset->pa.idle, 1, NULL);
    player->jump = (jump_t){0, 2, 2};
    player->roll = (roll_t){0, 1, 0};
    player->hor = 0;
    player->ver = 0;
    player->grounded = 0;
    player->dir = 1;
    player->velocity = 0;
    rpg->player = player;
    loading_screen(rpg, rpg->loading, 80, 1);
}
