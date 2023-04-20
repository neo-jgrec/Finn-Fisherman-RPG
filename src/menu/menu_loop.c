/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu_loop
*/

#include "rpg.h"
#include <sys/queue.h>

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list);
void saves_menu(win_t *win, rpg_t *rpg);

static void event_manager(win_t *win, UNUSED rpg_t *rpg)
{
    sfShader_setFloatUniform(rpg->menu->bg_shader, "time",
    DELTAT(rpg->win->time));
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed) {
            sfRenderWindow_close(win->win);
            rpg->win->scene = NONE;
        }
        if (win->event.type == sfEvtKeyPressed &&
            win->event.key.code == sfKeyEscape)
            rpg->menu->scene = MAIN_MENU;
    }
}

static void res_button_switch(rpg_t *rpg)
{
    button_t *button = NULL;

    TAILQ_FOREACH(button, &(rpg->menu->settings_buttons), next) {
        (rpg->win->win_style && !my_strcmp(button->name, "WINDOWED")) ?
            button->name = "FULLSCREEN" : 0;
        (!rpg->win->win_style && !my_strcmp(button->name, "FULLSCREEN")) ?
            button->name = "WINDOWED" : 0;
    }
}

static void settings_menu(win_t *win, rpg_t *rpg)
{
    if (rpg->menu->scene == SETTINGS_MENU) {
        sfShader_setFloatUniform(rpg->menu->bg_shader, "blur", 5.0);
        sfShader_setFloatUniform(rpg->menu->bg_shader, "brightness", 0.5);
        event_manager(win, rpg);
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawRectangleShape(win->win, rpg->menu->bg,
            rpg->menu->render_states);
        res_button_switch(rpg);
        (rpg->win->win_style == 1) ? button_manager(win, rpg,
            (struct buttons *)&(rpg->menu->res_buttons)) : 0;
        button_manager(win, rpg,
            (struct buttons *)&(rpg->menu->settings_buttons));
        sfText_setString(rpg->menu->text, "SETTINGS");
        sfText_setCharacterSize(rpg->menu->text, 50);
        sfText_setPosition(rpg->menu->text, (sfVector2f){sfRenderWindow_getSize
            (win->win).x / 2 - TEXT_SIZE_LEN("SETTINGS", 50) / 2, 50});
        sfRenderWindow_drawText(win->win, rpg->menu->text, NULL);
        sfRenderWindow_display(win->win);
    }
}

void menu_loop(win_t *win, rpg_t *rpg)
{
    if (rpg->menu->scene == MAIN_MENU) {
        sfShader_setFloatUniform(rpg->menu->bg_shader, "blur", 1.0);
        sfShader_setFloatUniform(rpg->menu->bg_shader, "brightness", 1.0);
        event_manager(win, rpg);
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawRectangleShape(win->win, rpg->menu->bg,
        rpg->menu->render_states);
        button_manager(win, rpg, &(rpg->menu->buttons));
        sfRenderWindow_display(win->win);
    }
    settings_menu(win, rpg);
    saves_menu(win, rpg);
}
