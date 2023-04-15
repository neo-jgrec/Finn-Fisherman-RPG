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
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
    }
}

static void settings_menu(win_t *win, rpg_t *rpg)
{
    if (rpg->menu->scene == SETTINGS_MENU) {
        event_manager(win, rpg);
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawRectangleShape(win->win, rpg->menu->bg, NULL);
        button_t *button = NULL;
        TAILQ_FOREACH(button, &(rpg->menu->settings_buttons), next) {
            if (rpg->win->win_style == 1 && my_strcmp(button->name, "WINDOWED") == 0)
                button->name = "FULLSCREEN";
            else if (rpg->win->win_style == 0 && my_strcmp(button->name, "FULLSCREEN") == 0) {
                button->name = "WINDOWED";
            }
        }
        if (rpg->win->win_style == 1)
            button_manager(win, rpg, (struct buttons *)&(rpg->menu->res_buttons));
        button_manager(win, rpg, (struct buttons *)&(rpg->menu->settings_buttons));
        sfRenderWindow_display(win->win);
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
    settings_menu(win, rpg);
}
