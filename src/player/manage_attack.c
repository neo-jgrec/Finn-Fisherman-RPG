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
        player->roll.cd > 0.3) {
        player->hor = rpg->input->right.press - rpg->input->left.press;
        player->state = ATTACK;
        play_sound(SWORD_SOUND, rpg);
        if (my_random(0, 100) < rpg->data->tot_stat.crit_chance)
            player->attack.crit = 1;
        else
            player->attack.crit = 0;
    }
    player->attack.save = rpg->input->attack.press;
}
