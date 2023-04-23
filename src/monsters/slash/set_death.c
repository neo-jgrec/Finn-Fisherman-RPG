/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_death
*/

#include "rpg.h"

void set_death(rpg_t *rpg, entity_t *entity)
{
    entity->health.health = 0;
    entity->time = 0;
    if (entity->id == SLASH)
        set_animation(entity, rpg->asset->ma_ball.death, 0, NULL);
    if (entity->id == BALL)
        set_animation(entity, rpg->asset->ma_ball.attack_2, 0, NULL);
}
