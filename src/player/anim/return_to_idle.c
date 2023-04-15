/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** return_to_idle
*/

#include "rpg.h"

void return_to_idle(rpg_t *rpg)
{
    rpg->player->roll.cd = 0;
    rpg->player->hor = rpg->input->right.press - rpg->input->left.press;
    rpg->player->state = IDLE;
}
