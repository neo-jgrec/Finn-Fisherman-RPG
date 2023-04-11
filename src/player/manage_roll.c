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
        roll->save != rpg->input->bot.press)
        roll->press_time = 0;
    roll->save = rpg->input->bot.press;
    roll->save_dir = player->dir;
    roll->press_time += rpg->win->deltaT;
}

void manage_roll(player_t *player, rpg_t *rpg)
{
    roll_t *roll = &player->roll;
    set_roll_var(player, rpg, roll);
    if (roll->press_time < 0.12 && player->grounded) {
        player->state = ROLL;
        roll->press_time = 10;
    }
    printf("%d\n", player->state);
}
