/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** heal_anim
*/

#include "rpg.h"

void heal_anim(rpg_t *rpg)
{
    rpg->player->state = IDLE;
    rpg->player->roll.cd = 0;
    set_animation(rpg->player, rpg->asset->pa.idle, 1, NULL);
    rpg->player->health.health += rpg->data->heal_power;
    if (rpg->player->health.health > rpg->data->max_health)
        rpg->player->health.health = rpg->data->max_health;
}
