/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_jump
*/

#include "rpg.h"

static void set_jump_var(player_t *player, rpg_t *rpg)
{
    if (player->grounded)
        player->jump.ground_time = 0;
    if (player->jump.save == 0 &&
        player->jump.save != rpg->input->space.press)
        player->jump.press_time = 0;
    player->jump.save = rpg->input->space.press;
    player->jump.ground_time += rpg->win->deltaT;
    player->jump.press_time += rpg->win->deltaT;
}

void manage_jump(player_t *player, rpg_t *rpg)
{
    set_jump_var(player, rpg);

    return;
}
