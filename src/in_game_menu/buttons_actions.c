/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** buttons_actions
*/

#include "rpg.h"

void menu_button_action(rpg_t *rpg)
{
    rpg->win->scene = MENU;
}

void settings_button_action(rpg_t *rpg)
{
    rpg->menu->in_game_menu->panel_type = SETTINGS_PANEL;
}

void save_button_action(rpg_t *rpg)
{
    rpg->menu->in_game_menu->panel_type = SAVE_PANEL;
}

void resume_button_action(rpg_t *rpg)
{
    rpg->menu->in_game_menu->panel_type = NONE_PANEL;
}

void inventory_button_action(rpg_t *rpg)
{
    rpg->menu->in_game_menu->panel_type = INVENTORY_PANEL;
}
