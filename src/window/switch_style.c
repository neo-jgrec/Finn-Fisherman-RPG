/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** switch_style
*/

#include "rpg.h"

void switch_style(win_t *win)
{
    win->win_style = 1 - win->win_style;
    if (win->win_style == 1) {
        sfRenderWindow_close(win->win);
        win->win = sfRenderWindow_create(
            (sfVideoMode){win->size.x, win->size.y, 32},
            "THE RPG", sfClose, NULL);
    } else {
        sfRenderWindow_close(win->win);
        win->win = sfRenderWindow_create(
            (sfVideoMode){win->size.x, win->size.y, 32},
            "THE RPG", sfFullscreen, NULL);
    }
}
