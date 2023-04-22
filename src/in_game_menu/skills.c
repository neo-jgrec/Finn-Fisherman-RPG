/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** skills
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

void draw_characteristics(win_t *win, rpg_t *rpg)
{
    event_manager(win, rpg);
    button_manager(win, rpg, (struct buttons *)&(rpg->menu->in_game_menu
        ->skill_buttons));
}
