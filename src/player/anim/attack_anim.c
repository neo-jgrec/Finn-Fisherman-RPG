/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** attack_anim
*/

#include "rpg.h"

void attack_anim(rpg_t *rpg)
{
    if (rpg->player->attack.crit) {
        return_to_idle(rpg);
    } else {
        set_animation(rpg->player,
            rpg->asset->pa.attack_1_2, 0, return_to_idle);
    }
}
