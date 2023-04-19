/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** button_save_manager
*/

#include "rpg.h"
#include <sys/syscall.h>

void create_default_save_file(char *filename, char *save_name);

static void rm_save(char *name)
{
    FILE *file = fopen(name, "w");

    create_default_save_file(name, name);
    fclose(file);
}

static void button_state(sfRenderWindow *win, button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    if (is_rect_hover(mouse_pos, sfRectangleShape_getPosition(button->shape),
        sfRectangleShape_getSize(button->shape))
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        button->state = CLICKED_BUTTON;
        return;
    }
    if (is_rect_hover(mouse_pos, sfRectangleShape_getPosition(button->shape),
        sfRectangleShape_getSize(button->shape))) {
        button->state = HOVER_BUTTON;
        return;
    }
    button->state = IDLE_BUTTON;
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
            rpg->menu->selected_save = button->name;
            button->action(rpg);
            break;
    }
}

void button_manager_save(win_t *win, rpg_t *rpg)
{
    for (size_t i = 0; i < 3; i++) {
        button_state(win->win, rpg->menu->saves[i]->button);
        change_button_style(rpg->menu->saves[i]->button, rpg);
        if (rpg->menu->saves[i]->button->state == HOVER_BUTTON
            && sfKeyboard_isKeyPressed(sfKeyR)) {
            rm_save(rpg->menu->saves[i]->save_file);
            rpg->menu->saves[i]->is_write = false;
            rpg->menu->saves[i]->name = NULL;
            rpg->menu->saves[i]->button->name = NULL;
        }
    }
}
