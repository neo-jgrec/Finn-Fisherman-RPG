/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** play
*/

#include "rpg.h"

void quit_button(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->win->win);
}

void settings_button(rpg_t *rpg)
{
    rpg->menu->scene = SETTINGS_MENU;
}

void play_button(rpg_t *rpg)
{
    rpg->menu->scene = SAVES_MENU;
}
