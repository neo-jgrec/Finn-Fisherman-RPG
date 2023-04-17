/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** hit_player
*/

#include "rpg.h"

void hit_player(rpg_t *rpg, int damage, entity_t *entity)
{
    if (entity->state != HIT && entity->health.damage_cd > 1) {
        entity->state = HIT;
        entity->health.damage_cd = 0;
        entity->health.health -= damage;
        if (entity->health.health < 0)
            entity->health.health = 0;
    }
}
