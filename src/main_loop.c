/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main_loop
*/

#include "rpg.h"

static void analyse_events(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
    }
}

int main_loop(win_t *win, rpg_t *rpg)
{
    int i = 0;

    while (sfRenderWindow_isOpen(win->win)) {
        sfRenderWindow_clear(win->win, sfGreen);
        analyse_events(win);
        sfRenderWindow_display(win->win);
    }
    return 0;
}
