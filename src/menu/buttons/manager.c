/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manager
*/

#include "rpg.h"

static void button_state(sfRenderWindow *win, button_t *button, rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f button_pos = sfRectangleShape_getPosition(button->shape);
    sfVector2f button_size = sfRectangleShape_getSize(button->shape);

    if (is_rect_hover(mouse_pos, button_pos, button_size)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            button->state = CLICKED_BUTTON;
            button->action(rpg);
        } else
            button->state = HOVER_BUTTON;
    } else
        button->state = IDLE_BUTTON;
}

static void change_button_style(button_t *button)
{
    sfColor white_with_alpha = {255, 255, 255, 100};

    switch (button->state) {
        case IDLE_BUTTON:
            sfRectangleShape_setFillColor(button->shape, white_with_alpha);
            break;
        case HOVER_BUTTON:
            sfRectangleShape_setFillColor(button->shape, sfWhite);
            break;
        case CLICKED_BUTTON:
            sfRectangleShape_setFillColor(button->shape, sfBlue);
            break;
    }
}

void button_manager(button_t *button, win_t *win, rpg_t *rpg)
{
    sfText *text = sfText_create();

    TAILQ_FOREACH(button, &rpg->menu->buttons, next) {
        button_state(win->win, button, rpg);
        change_button_style(button);
        sfText_setString(text, button->name);
        sfText_setColor(text, sfBlack);
        sfText_setFont(text, rpg->menu->font);
        sfText_setCharacterSize(text, 30);
        sfText_setPosition(text, button->pos);
        sfRenderWindow_drawRectangleShape(win->win, button->shape, NULL);
        sfRenderWindow_drawText(win->win, text, NULL);
    }
}
