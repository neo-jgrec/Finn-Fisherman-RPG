/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_loop
*/

#include "rpg.h"

static void button_manager(button_t *button, win_t *win, rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win->win);

    TAILQ_FOREACH(button, &rpg->menu->buttons, next) {
        if (mouse_pos.x >= button->pos.x && mouse_pos.x <= button->pos.x + button->size.x &&
            mouse_pos.y >= button->pos.y && mouse_pos.y <= button->pos.y + button->size.y) {
            button->action(rpg);
        }
    }
}

void menu_loop(win_t *win, rpg_t *rpg)
{
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_drawRectangleShape(win->win, rpg->menu->bg, NULL);
    sfRenderWindow_drawText(win->win, rpg->menu->text, NULL);
    sfRenderWindow_display(win->win);
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
        if (win->event.type == sfEvtMouseButtonPressed)
            button_manager(rpg->menu->buttons.tqh_first, win, rpg);
    }
}
