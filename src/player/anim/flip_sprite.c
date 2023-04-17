/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** flip_sprite
*/

#include "rpg.h"

void flip(entity_t *player)
{
    VEC scale = sfSprite_getScale(player->sp);

    if (player->hor == 1)
        player->dir = 1;
    if (player->hor == -1)
        player->dir = -1;
    sfSprite_setScale(player->sp,
        (VEC){player->dir * fabs(scale.x), scale.y});
}
