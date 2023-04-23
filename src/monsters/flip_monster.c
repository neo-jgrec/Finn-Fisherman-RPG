/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** flip_monster
*/

#include "rpg.h"

void flip_monster(entity_t *monster, entity_t *player)
{
    VEC scale = sfSprite_getScale(monster->sp);
    float dist = monster->pos.x - player->pos.x;

    if (monster->state != ATTACK)
        monster->dir = -(SIGN(dist));
    sfSprite_setScale(monster->sp,
        (VEC){monster->dir * fabs(scale.x), scale.y});
}
