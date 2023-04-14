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
    return;
}

void play_button(rpg_t *rpg)
{
    rpg->win->scene = GAME;
}
