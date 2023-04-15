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

void res_button(rpg_t *rpg)
{
    if (rpg->win->win_style == 1) {
        sfRenderWindow_close(rpg->win->win);
        rpg->win->win = sfRenderWindow_create((sfVideoMode){1600, 900, 32},
            "THE RPG", sfFullscreen, NULL);
        sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
        sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1920, 1080});
        rpg->win->win_style = 0;
    } else {
        sfRenderWindow_close(rpg->win->win);
        rpg->win->win = sfRenderWindow_create((sfVideoMode){1600, 900, 32},
            "THE RPG", sfClose, NULL);
        sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
        sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1600, 900});
        rpg->win->win_style = 1;
    }
}
