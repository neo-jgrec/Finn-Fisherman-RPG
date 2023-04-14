/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_loop
*/

#include "rpg.h"
#include <sys/queue.h>

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list);

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
    if (rpg->menu->scene == MAIN_MENU) {
        event_manager(win, rpg);
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawRectangleShape(win->win, rpg->menu->bg, NULL);
        button_manager(win, rpg, &(rpg->menu->buttons));
        sfRenderWindow_display(win->win);
    }
}
