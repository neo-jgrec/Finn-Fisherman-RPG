/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** return_to_idle
*/

#include "rpg.h"

void return_to_idle(rpg_t *rpg)
{
    rpg->player->state = IDLE;
    rpg->player->roll.cd = 0;
    set_animation(rpg->player, rpg->asset->pa.idle, 1, NULL);
}
