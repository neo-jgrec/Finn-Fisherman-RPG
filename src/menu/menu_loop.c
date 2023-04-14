/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_loop
*/

#include "rpg.h"

void button_manager(button_t *button, win_t *win, rpg_t *rpg);

static void event_manager(win_t *win, UNUSED rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
    }
}

void menu_loop(win_t *win, rpg_t *rpg)
{
    button_t *button = NULL;

    if (rpg->menu->scene == MAIN_MENU) {
        event_manager(win, rpg);
        sfRenderWindow_clear(win->win, sfBlack);
        button_manager(button, win, rpg);
        sfRenderWindow_display(win->win);
    }
}
