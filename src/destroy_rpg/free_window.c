/*
** EPITECH PROJECT, 2023
** free_window
** File description:
** free_window
*/

#include "rpg.h"

void free_window(win_t *win)
{
    if (win){
        sfImage_destroy(win->icon);
        sfRenderWindow_destroy(win->win);
        sfFont_destroy(win->font);
        sfClock_destroy(win->time);
        sfClock_destroy(win->warudo);
        free(win);
    }
}
