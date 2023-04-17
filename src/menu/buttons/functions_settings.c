/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** functions_settings
*/

#include "rpg.h"

void back_button(rpg_t *rpg)
{
    rpg->menu->scene = MAIN_MENU;
}

static void re_set_res_button_pos(rpg_t *rpg)
{
    button_t *button = NULL;

    TAILQ_FOREACH(button, &rpg->menu->res_buttons, next) {
        button->pos = (sfVector2f)
            {sfRenderWindow_getSize(rpg->win->win).x - 210, button->pos.y};
        sfRectangleShape_setPosition(button->shape, button->pos);
    }
}

void res_button(rpg_t *rpg)
{
    if (rpg->win->win_style == 1) {
        sfRenderWindow_close(rpg->win->win);
        rpg->win->win = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
            "THE RPG", 0, NULL);
        sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
        sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1920, 1080});
        rpg->win->win_style = 0;
        re_set_res_button_pos(rpg);
    } else {
        sfRenderWindow_close(rpg->win->win);
        rpg->win->win = sfRenderWindow_create((sfVideoMode){1600, 900, 32},
            "THE RPG", sfClose, NULL);
        sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
        sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1600, 900});
        rpg->win->win_style = 1;
        re_set_res_button_pos(rpg);
    }
}
