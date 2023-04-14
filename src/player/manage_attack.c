/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_attack
*/

#include "rpg.h"

void manage_attack(entity_t *player, rpg_t *rpg)
{
    if (player->state != ATTACK &&
        player->attack.save != rpg->input->attack.press &&
        player->roll.cd > 0.1) {
        player->state = ATTACK;
        if (my_random(0, 100) < rpg->data->crit_chance)
            player->attack.crit = 1;
        else
            player->attack.crit = 0;
    }
    player->attack.save = rpg->input->attack.press;
}
