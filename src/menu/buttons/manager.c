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
    sfVector2f mouse_pos_view = sfRenderWindow_mapPixelToCoords(win,
        sfMouse_getPositionRenderWindow(win), sfRenderWindow_getView(win));
    sfVector2i mouse_pos = (sfVector2i) {mouse_pos_view.x, mouse_pos_view.y};

    if (button->state == CLICKED_BUTTON
    && !sfMouse_isButtonPressed(sfMouseLeft)) {
        button->state = IDLE_BUTTON;
        if (button->action) button->action(rpg);
        return;
    }
    if (is_rect_hover(mouse_pos, button->pos, button->size)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        button->state = CLICKED_BUTTON;
        return;
    }
    if (is_rect_hover(mouse_pos, button->pos, button->size)) {
        button->state = HOVER_BUTTON;
        return;
    }
    button->state = IDLE_BUTTON;
}

static void change_button_style(button_t *button, UNUSED rpg_t *rpg)
{
    switch (button->state) {
        case IDLE_BUTTON:
            sfText_setCharacterSize(rpg->menu->text, 30);
            sfText_setStyle(rpg->menu->text, sfTextRegular);
            sfText_setColor(rpg->menu->text, sfWhite);
            break;
        case HOVER_BUTTON:
            sfText_setCharacterSize(rpg->menu->text, 35);
            break;
        case CLICKED_BUTTON:
            sfText_setCharacterSize(rpg->menu->text, 35);
            sfText_setStyle(rpg->menu->text, sfTextBold);
            sfText_setColor(rpg->menu->text, sfRed);
            break;
    }
}

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list)
{
    button_t *button = NULL;

    TAILQ_FOREACH(button, button_list, next) {
        if (rpg->menu->in_game_menu->panel_type == SETTINGS_PANEL
        && !my_strcmp(button->name, "<-"))
            continue;
        sfText_setStyle(rpg->menu->text, sfTextRegular);
        button_state(win->win, button, rpg);
        change_button_style(button, rpg);
        sfText_setString(rpg->menu->text, button->name);
        sfText_setFont(rpg->menu->text, rpg->menu->font);
        sfText_setPosition(rpg->menu->text, button->pos);
        sfRenderWindow_drawText(win->win, rpg->menu->text, NULL);
    }
}
