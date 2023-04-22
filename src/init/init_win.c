/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_win
*/

#include "rpg.h"

static void init_icon(win_t *win)
{
    win->icon = sfImage_createFromFile("assets/icon.png");
    sfRenderWindow_setIcon(win->win, sfImage_getSize(win->icon).x,
        sfImage_getSize(win->icon).y, sfImage_getPixelsPtr(win->icon));
}

void init_win(rpg_t *rpg)
{
    win_t *win = malloc(sizeof(win_t));
    sfEvent event = {0};

    if (win == NULL)
        rpg->win = NULL;
    win->win = sfRenderWindow_create((sfVideoMode){1600, 900, 32},
        "THE RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win->win, 60);
    win->event = event;
    win->time = sfClock_create();
    win->warudo = sfClock_create();
    win->deltaT = 0;
    win->scene = MENU;
    win->font = sfFont_createFromFile("assets/AwasetePowder.ttf");
    win->size = (sfVector2u){1600, 900};
    win->win_size = 0;
    win->win_style = 1;
    win->save_key = 0;
    init_icon(win);
    rpg->win = win;
}
