/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** hit_player
*/

#include "rpg.h"

void hit_player(UNUSED rpg_t *rpg, int damage, entity_t *entity)
{
    if (entity->state != HIT && entity->health.damage_cd > 0.3) {
        entity->health.cd = 0;
        entity->state = HIT;
        entity->health.damage_cd = 0;
        entity->health.health -= damage;
        if (entity->health.health < 0)
            entity->health.health = 0;
        add_info_text(rpg, sfRed,
        (VEC){entity->pos.x, entity->pos.y - 50}, my_itoa(-damage));
    }
}
