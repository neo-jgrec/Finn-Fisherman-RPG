/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** button_save_manager
*/

#include "rpg.h"

static void button_state(sfRenderWindow *win, button_t *button,
UNUSED rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    if (is_rect_hover(mouse_pos, sfRectangleShape_getPosition(button->shape),
    sfRectangleShape_getSize(button->shape))
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        button->state = CLICKED_BUTTON;
    } else if (is_rect_hover(mouse_pos,
    sfRectangleShape_getPosition(button->shape),
    sfRectangleShape_getSize(button->shape))) {
        button->state = HOVER_BUTTON;
    } else {
        button->state = IDLE_BUTTON;
    }
}

static void change_button_style(button_t *button, rpg_t *rpg)
{
    switch (button->state) {
        case IDLE_BUTTON:
            sfRectangleShape_setOutlineThickness(button->shape, 0);
            break;
        case HOVER_BUTTON:
            sfRectangleShape_setOutlineThickness(button->shape, 5);
            sfRectangleShape_setOutlineColor(button->shape, sfBlack);
            break;
        case CLICKED_BUTTON:
            sfRectangleShape_setOutlineColor(button->shape, sfRed);
            button->action(rpg);
            break;
    }
}

void button_manager_save(win_t *win, rpg_t *rpg)
{
    for (size_t i = 0; i < 3; i++) {
        button_state(win->win, rpg->menu->saves[i]->button, rpg);
        change_button_style(rpg->menu->saves[i]->button, rpg);
    }
}
