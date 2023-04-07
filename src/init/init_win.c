/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_win
*/

#include "rpg.h"

win_t *init_win(void)
{
    win_t *win = malloc(sizeof(win_t));
    sfEvent event = {0};

    if (win == NULL)
        return NULL;
    win->win = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "THE RPG", sfFullscreen, NULL);
    win->event = event;
    win->time = sfClock_create();
    win->deltaT = 0;
    win->scene = LOADING;
    return win;
}
