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
    if (rpg->input->space.press == 0 && player->velocity < 0)
        player->velocity = 0;
    if (jump->save == 0 &&
        jump->save != rpg->input->space.press)
        jump->press_time = 0;
    jump->save = rpg->input->space.press;
    jump->ground_time += rpg->win->deltaT;
    jump->press_time += rpg->win->deltaT;
}

void manage_jump(player_t *player, rpg_t *rpg)
{
    jump_t *jump = &player->jump;

    set_jump_var(player, rpg, jump);
    if ((jump->ground_time < 0.12 ||
        (player->jump.nb != 0 && rpg->input->space.press))
        && jump->press_time < 0.12) {
        if (jump->ground_time >= 0.12)
            player->jump.nb -= 1;
        player->velocity = -800;
        jump->press_time = 10;
    }
}
