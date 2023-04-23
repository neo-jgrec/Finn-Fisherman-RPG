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
    set_animation(entity, rpg->asset->ma_ball.death, 1, NULL);
}