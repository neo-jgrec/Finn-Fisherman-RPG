/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** move_player
*/

#include "rpg.h"

void move_player(entity_t *player, sfVector2f dir)
{
    if (player->id != PLAYER && dir.y > 10)
        dir.y = 10;
    player->pos.y += dir.y;
    player->pos.x += dir.x;
    player->rect = (sfFloatRect){player->pos.x - (player->rect.width / 2),
        player->pos.y - (player->rect.height / 2),
        player->rect.width, player->rect.height};
}
