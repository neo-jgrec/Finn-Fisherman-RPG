/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** switch_size
*/

#include "rpg.h"

void switch_size(win_t *win)
{
    win->win_size = 1 - win->win_size;
    if (win->win_size == 1)
        win->size = (sfVector2u){1600, 900};
    else
        win->size = (sfVector2u){1920, 1080};
    sfRenderWindow_setSize(win->win, win->size);
}
