/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_roll
*/

#include "rpg.h"

static void set_roll_var(player_t *player, rpg_t *rpg, roll_t *roll)
{
    if (roll->save == 0 &&
        roll->save != rpg->input->roll.press)
        roll->press_time = 0;
    roll->save = rpg->input->roll.press;
    roll->save_dir = player->dir;
    roll->press_time += rpg->win->deltaT;
    roll->cd += rpg->win->deltaT;
}

void manage_roll(player_t *player, rpg_t *rpg)
{
    roll_t *roll = &player->roll;

    set_roll_var(player, rpg, roll);
    if (roll->press_time < 0.12 && player->grounded && roll->cd > 0.1) {
        player->state = ROLL;
        roll->press_time = 10;
    }
}
