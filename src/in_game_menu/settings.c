/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings
*/

#include "rpg.h"

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list);

static void event_manager(win_t *win, UNUSED rpg_t *rpg)
{
    if (win->event.type == sfEvtClosed) {
        sfRenderWindow_close(win->win);
        rpg->win->scene = NONE;
    }
    sfRenderWindow_setView(win->win, sfRenderWindow_getDefaultView(win->win));
}

static void res_button_switch(rpg_t *rpg)
{
    button_t *button = NULL;

    TAILQ_FOREACH(button, &(rpg->menu->settings_buttons), next) {
        (rpg->win->win_style && !my_strcmp(button->name, "WINDOWED")) ?
            button->name = "FULLSCREEN" : 0;
        (!rpg->win->win_style && !my_strcmp(button->name, "FULLSCREEN")) ?
            button->name = "WINDOWED" : 0;
    }
}

void settings_menu(win_t *win, rpg_t *rpg)
{
    if (rpg->menu->in_game_menu->panel_type == SETTINGS_PANEL) {
        event_manager(win, rpg);
        res_button_switch(rpg);
            (rpg->win->win_style == 1) ? button_manager(win, rpg,
                (struct buttons *)&(rpg->menu->res_buttons)) : 0;
            button_manager(win, rpg,
                (struct buttons *)&(rpg->menu->settings_buttons));
    }
}
