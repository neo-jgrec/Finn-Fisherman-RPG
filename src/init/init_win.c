/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_win
*/

#include "rpg.h"

void init_win(rpg_t *rpg)
{
    win_t *win = malloc(sizeof(win_t));
    sfEvent event = {0};

    if (win == NULL)
        rpg->win = NULL;
    win->win = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "THE RPG", sfDefaultStyle, NULL);
    win->event = event;
    win->time = sfClock_create();
    win->deltaT = 0;
    win->scene = LOADING;
    rpg->win = win;
}
