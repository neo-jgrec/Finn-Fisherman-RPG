/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_player
*/

#include "rpg.h"

player_t *init_player(asset_t *asset)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->pos = (VEC){500, 500};
    player->rect = (sfFloatRect){0};
    player->time = sfClock_create();
    player->sp = asset->player->sp;
    player->size = asset->player->size.x;
    player->nb_frame = asset->player->nb_frame;
    player->cd_frame = 0.2f;
    return player;
}
