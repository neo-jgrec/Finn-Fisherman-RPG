/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** heal_anim
*/

#include "rpg.h"

void heal_anim(rpg_t *rpg, entity_t *entity)
{
    entity->state = IDLE;
    entity->roll.cd = 0;
    set_animation(entity, rpg->asset->pa.idle, 1, NULL);
    entity->health.health += rpg->data->tot_stat.heal_power;
    if (entity->health.health > rpg->data->tot_stat.max_health)
        entity->health.health = rpg->data->tot_stat.max_health;
}
