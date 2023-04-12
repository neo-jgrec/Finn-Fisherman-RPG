/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** hit_player
*/

#include "rpg.h"

void hit_player(rpg_t *rpg, int damage)
{
    if (rpg->player->state != HIT && rpg->player->health.damage_cd > 1) {
        rpg->player->state = HIT;
        rpg->player->health.damage_cd = 0;
        rpg->player->health.health -= damage;
        if (rpg->player->health.health < 0)
            rpg->player->health.health = 0;
    }
}
