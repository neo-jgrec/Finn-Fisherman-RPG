/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** button_actions2
*/

#include "rpg.h"

void skills_button_action(rpg_t *rpg)
{
    rpg->menu->in_game_menu->panel_type = CHARACTERISTICS_PANEL;
}

void how_to_play_button_action(rpg_t *rpg)
{
    rpg->menu->in_game_menu->panel_type = HOW_TO_PLAY_PANEL;
}
