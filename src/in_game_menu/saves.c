/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** saves
*/

#include "rpg.h"

void button_manager_save(win_t *win, rpg_t *rpg);

static void event_manager(win_t *win, UNUSED rpg_t *rpg)
{
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->win);
    if (win->event.type == sfEvtKeyPressed &&
        win->event.key.code == sfKeyEscape)
        rpg->menu->scene = MAIN_MENU;
    sfRenderWindow_setView(win->win, sfRenderWindow_getDefaultView(win->win));
}

static void display_save(win_t *win, rpg_t *rpg)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_setFillColor(rpg->menu->saves[i]->button->shape,
            ALPHA_WHITE);
        sfText_setString(rpg->menu->text, rpg->menu->saves[i]->is_write ?
            rpg->menu->saves[i]->name : "EMPTY");
        sfText_setCharacterSize(rpg->menu->text, 50);
        sfText_setPosition(rpg->menu->text, (sfVector2f)
            {sfRectangleShape_getPosition
            (rpg->menu->saves[i]->button->shape).x + sfRectangleShape_getSize
            (rpg->menu->saves[i]->button->shape).x / 2 - TEXT_SIZE_LEN(
            rpg->menu->saves[i]->is_write ? rpg->menu->saves[i]->name :
            "EMPTY", 50) / 2, sfRectangleShape_getPosition(
            rpg->menu->saves[i]->button->shape).y + sfRectangleShape_getSize(
            rpg->menu->saves[i]->button->shape).y / 2 - 25});
        sfRenderWindow_drawText(win->win, rpg->menu->text, NULL);
        sfRenderWindow_drawRectangleShape(win->win,
            rpg->menu->saves[i]->button->shape, NULL);
    }
}

void saves_menu_in_game(win_t *win, rpg_t *rpg)
{
    sfText_setColor(rpg->menu->text, sfWhite);
    sfText_setStyle(rpg->menu->text, sfTextRegular);
    event_manager(win, rpg);
    button_manager_save(win, rpg);
    display_save(win, rpg);
    sfRenderWindow_drawText(win->win, rpg->menu->text, NULL);
}
