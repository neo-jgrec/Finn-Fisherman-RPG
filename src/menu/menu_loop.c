/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_loop
*/

#include "rpg.h"
#include <sys/queue.h>

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list);
char **read_dir(char *folder);

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
        sfRenderWindow_drawRectangleShape(win->win, rpg->menu->bg,
            rpg->menu->render_states);
        button_t *button = NULL;
        TAILQ_FOREACH(button, &(rpg->menu->settings_buttons), next) {
            (rpg->win->win_style && !my_strcmp(button->name, "WINDOWED")) ?
                button->name = "FULLSCREEN" : 0;
            (!rpg->win->win_style && !my_strcmp(button->name, "FULLSCREEN")) ?
                button->name = "WINDOWED" : 0;
        }
        (rpg->win->win_style == 1) ? button_manager(win, rpg,
            (struct buttons *)&(rpg->menu->res_buttons)) : 0;
        button_manager(win, rpg,
            (struct buttons *)&(rpg->menu->settings_buttons));
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
