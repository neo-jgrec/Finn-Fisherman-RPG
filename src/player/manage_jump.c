/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_jump
*/

#include "rpg.h"

static void set_jump_var(player_t *player, rpg_t *rpg, jump_t *jump)
{
    if (player->grounded)
        jump->ground_time = 0;
    if (rpg->input->space.press == 0 && jump->jump > 0)
        jump->jump = -1;
    if (jump->save == 0 &&
        jump->save != rpg->input->space.press)
        jump->press_time = 0;
    jump->save = rpg->input->space.press;
    jump->ground_time += rpg->win->deltaT;
    jump->press_time += rpg->win->deltaT;
    jump->jump -= rpg->win->deltaT;
}

void manage_jump(player_t *player, rpg_t *rpg)
{
    jump_t *jump = &player->jump;

    set_jump_var(player, rpg, jump);
    if (jump->ground_time < 0.1 && jump->press_time < 0.1 && jump->jump < 0)
        jump->jump = 0.25;
    if (jump->jump > 0) {
        move_player(player, (VEC){0, -jump->jump * rpg->win->deltaT * 6000});
        check_collision(player, rpg->puzzle, 0);
    }
}
