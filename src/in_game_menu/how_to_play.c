/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** how_to_play
*/

#include "rpg.h"

static void event_manager(win_t *win, rpg_t *rpg)
{
    if (win->event.type == sfEvtClosed) {
        sfRenderWindow_close(win->win);
        rpg->win->scene = NONE;
    }
    sfRenderWindow_setView(win->win, sfRenderWindow_getDefaultView(win->win));
}

void draw_how_to(win_t *win, rpg_t *rpg)
{
    event_manager(win, rpg);
    sfRectangleShape_setSize(rpg->menu->how_to_play, (sfVector2f)
        {sfRenderWindow_getSize(win->win).x / 2, sfRenderWindow_getSize(
        win->win).y / 2});
    sfRectangleShape_setPosition(rpg->menu->how_to_play, (sfVector2f)
        {sfRenderWindow_getSize(win->win).x / 2 - sfRectangleShape_getSize(
        rpg->menu->how_to_play).x / 2, sfRenderWindow_getSize(win->win).y / 2 -
        sfRectangleShape_getSize(rpg->menu->how_to_play).y / 2});
    sfRenderWindow_drawRectangleShape(win->win, rpg->menu->how_to_play, NULL);
}
