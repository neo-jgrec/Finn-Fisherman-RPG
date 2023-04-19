/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** death_anim
*/

#include "rpg.h"

void death_anim(rpg_t *rpg, entity_t *entity)
{
    if (entity->id == PLAYER) {
        entity->state = IDLE;
        entity->health.health = rpg->data->max_health;
        entity->health.potion = rpg->data->max_potion;
        rpg->data->xp = 0;
        entity->pos = rpg->puzzle->spawn;
        rpg->font_cpy->is_moved = false;
        rpg->player->health.cd = 0;
    }
    return;
}
