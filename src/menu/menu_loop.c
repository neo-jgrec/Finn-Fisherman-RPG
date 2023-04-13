/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_loop
*/

#include "rpg.h"

void menu_loop(win_t *win, rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(win->win);
    }
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_display(win->win);
}
