/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manager
*/

#include "rpg.h"
#include <sys/queue.h>

static void button_state(sfRenderWindow *win, button_t *button, rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    if (is_rect_hover(mouse_pos, button->pos, button->size)
    && (rpg->win->event.type == sfEvtMouseButtonPressed)) {
        button->state = CLICKED_BUTTON;
        if (rpg->win->event.type == sfEvtMouseButtonReleased)
            button->state = HOVER_BUTTON;
    } else if (is_rect_hover(mouse_pos, button->pos, button->size)) {
        button->state = HOVER_BUTTON;
    } else
        button->state = IDLE_BUTTON;
}

static void change_button_style(button_t *button, rpg_t *rpg)
{
    switch (button->state) {
        case IDLE_BUTTON:
            break;
        case HOVER_BUTTON:
            break;
        case CLICKED_BUTTON:
            button->action(rpg);
            break;
    }
}

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list)
{
    sfText *text = sfText_create();
    button_t *button = NULL;

    TAILQ_FOREACH(button, button_list, next) {
        button_state(win->win, button, rpg);
        change_button_style(button, rpg);
        sfText_setString(text, button->name);
        sfText_setFont(text, rpg->menu->font);
        sfText_setColor(text, sfWhite);
        sfText_setPosition(text, button->pos);
        sfText_setCharacterSize(text, 30);
        if (button->state == HOVER_BUTTON)
            sfText_setCharacterSize(text, 35);
        if (button->state == CLICKED_BUTTON) {
            sfText_setStyle(text, sfTextBold);
            sfText_setColor(text, sfRed);
        }
        sfRenderWindow_drawText(win->win, text, NULL);
    }
}
