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
    player->pos = (VEC){500, 500};
    player->rect = (sfFloatRect){0, 0, 64, 64};
    player->time = sfClock_create();
    player->sp = asset->player.sp;
    player->frame = (frame_t){asset->player.size.x,
        asset->player.nb_frame, 0.2f};
    player->jump = (jump_t){0, 0, 2, 2};
    player->hor = 0;
    player->ver = 0;
    player->grounded = 0;
    rpg->player = player;
    loading_screen(rpg, rpg->loading, 80, 1);

}
