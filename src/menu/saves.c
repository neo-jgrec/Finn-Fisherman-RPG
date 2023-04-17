/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** saves
*/

#include "rpg.h"

static void event_manager(win_t *win, UNUSED rpg_t *rpg)
{
    sfShader_setFloatUniform(rpg->menu->bg_shader, "time",
    DELTAT(rpg->win->time));
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
        if (win->event.type == sfEvtKeyPressed &&
            win->event.key.code == sfKeyEscape)
            rpg->menu->scene = MAIN_MENU;
    }
}

void saves_menu(win_t *win, rpg_t *rpg)
{
    if (rpg->menu->scene == SAVES_MENU) {
        sfShader_setFloatUniform(rpg->menu->bg_shader, "blur", 5.0);
        sfShader_setFloatUniform(rpg->menu->bg_shader, "brightness", 0.5);
        event_manager(win, rpg);
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawRectangleShape(win->win, rpg->menu->bg,
            rpg->menu->render_states);
        for (int i = 0; i < 3; i++) {
            sfRectangleShape_setFillColor(rpg->menu->saves[i]->button->shape,
                ALPHA_WHITE);
            sfRenderWindow_drawRectangleShape(win->win,
                rpg->menu->saves[i]->button->shape, NULL);
        } sfText_setString(rpg->menu->text, "SAVES");
        sfText_setCharacterSize(rpg->menu->text, 50);
        sfText_setPosition(rpg->menu->text, (sfVector2f){sfRenderWindow_getSize
            (win->win).x / 2 - TEXT_SIZE_LEN("SAVES", 50) / 2, 50});
        sfRenderWindow_drawText(win->win, rpg->menu->text, NULL);
        sfRenderWindow_display(win->win);
    }
}
