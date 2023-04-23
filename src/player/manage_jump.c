/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_jump
*/

#include "rpg.h"

static void set_jump_var(entity_t *player, rpg_t *rpg, jump_t *jump)
{
    if (player->grounded)
        jump->ground_time = 0;
    if (rpg->input->jump.press == 0 && player->velocity < 0)
        player->velocity = 0;
    if (jump->save == 0 &&
        jump->save != rpg->input->jump.press)
        jump->press_time = 0;
    jump->save = rpg->input->jump.press;
    jump->ground_time += rpg->win->deltaT;
    jump->press_time += rpg->win->deltaT;
}

void manage_jump(entity_t *player, rpg_t *rpg)
{
    jump_t *jump = &player->jump;

    set_jump_var(player, rpg, jump);
    if ((jump->ground_time < 0.12 ||
        (player->jump.nb != 0 && rpg->input->jump.press))
        && jump->press_time < 0.12) {
        play_sound(JUMP_SOUND, rpg);
        if (jump->ground_time >= 0.12)
            player->jump.nb -= 1;
        player->velocity = -850;
        jump->press_time = 10;
    }
}
