/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** function_res
*/

#include "rpg.h"

void res_1900_button(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->win->win);
    rpg->win->win = sfRenderWindow_create((sfVideoMode){1900, 1000, 32},
        "THE RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
    sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f){1900, 1000});
    rpg->win->win_style = 1;
}
