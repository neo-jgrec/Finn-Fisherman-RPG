/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** saves_action
*/

#include "rpg.h"

void launch_game(rpg_t *rpg)
{
    rpg->save_path = rpg->menu->selected_save;
    rpg->win->scene = GAME;
}
