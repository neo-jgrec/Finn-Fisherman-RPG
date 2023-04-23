/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** button_save_manager
*/

#include "rpg.h"
#include <sys/syscall.h>

static const sfVector2f b_size = {700, 150};

void create_default_save_file(char *filename, char *save_name);
void save_data_in_game(rpg_t *rpg, char *filename, char *save_name);
void parse_saves(menu_t *menu);

static void rm_save(char *name, size_t i)
{
    FILE *file = fopen(name, "w");

    create_default_save_file(name, my_strcat_inf(2, "Save ", my_itoa(i + 1)));
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

static void change_button_style(button_t *button, rpg_t *rpg, size_t i)
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
            rpg->menu->save_reference = i;
            rpg->menu->selected_save = button->name;
            button->action(rpg);
            break;
    }
}

void button_manager_save(win_t *win, rpg_t *rpg)
{
    parse_saves(rpg->menu);
    for (size_t i = 0; i < 3; i++) {
        sfVector2u win_size = sfRenderWindow_getSize(win->win);
        sfRectangleShape_setPosition(rpg->menu->saves[i]->button->shape,
            (sfVector2f){win_size.x / 2 - 350, 200 + 185 * i});
        sfRectangleShape_setSize(rpg->menu->saves[i]->button->shape, b_size);
        button_state(win->win, rpg->menu->saves[i]->button);
        change_button_style(rpg->menu->saves[i]->button, rpg, i);
        if (rpg->menu->saves[i]->button->state == HOVER_BUTTON
            && sfKeyboard_isKeyPressed(sfKeyR)) {
            rm_save(rpg->menu->saves[i]->save_file, i);
            rpg->menu->saves[i]->is_write = false;
        } if (rpg->menu->saves[i]->button->state == HOVER_BUTTON
            && sfKeyboard_isKeyPressed(sfKeyS)
            && rpg->menu->in_game_menu->panel_type == SAVE_PANEL) {
            save_data_in_game(rpg, rpg->menu->saves[i]->save_file,
                rpg->menu->saves[i]->name);
            rpg->menu->saves[i]->is_write = true;
        }
    }
}
