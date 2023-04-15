/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** function_res
*/

#include "rpg.h"

void res_1600_button(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->win->win);
    rpg->win->win = sfRenderWindow_create((sfVideoMode){1600, 900, 32},
        "THE RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
    sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1600, 900});
    button_t *button = NULL;
    TAILQ_FOREACH(button, &rpg->menu->res_buttons, next) {
        button->pos = (sfVector2f){1600 - 210, button->pos.y};
        sfRectangleShape_setPosition(button->shape, button->pos);
    }
    rpg->win->win_style = 1;
}

void res_1920_button(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->win->win);
    rpg->win->win = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "THE RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
    sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1920, 1080});
    button_t *button = NULL;
    TAILQ_FOREACH(button, &rpg->menu->res_buttons, next) {
        button->pos = (sfVector2f){1920 - 210, button->pos.y};
        sfRectangleShape_setPosition(button->shape, button->pos);
    }
    rpg->win->win_style = 1;
}

void res_800_button(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->win->win);
    rpg->win->win = sfRenderWindow_create((sfVideoMode){800, 600, 32},
        "THE RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
    sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){800, 600});
    button_t *button = NULL;
    TAILQ_FOREACH(button, &rpg->menu->res_buttons, next) {
        button->pos = (sfVector2f){800 - 210, button->pos.y};
        sfRectangleShape_setPosition(button->shape, button->pos);
    }
    rpg->win->win_style = 1;
}
