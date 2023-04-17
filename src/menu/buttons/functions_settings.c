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
    button_t *button;

    TAILQ_FOREACH(button, &rpg->menu->res_buttons, next) {
        button->pos = (sfVector2f)
            {sfRenderWindow_getSize(rpg->win->win).x - 210, button->pos.y};
        sfRectangleShape_setPosition(button->shape, button->pos);
    }
}

void res_button(rpg_t *rpg)
{
    switch_style(rpg->win);
    sfRectangleShape_setSize(rpg->menu->bg, (sfVector2f)
        {sfRenderWindow_getSize(rpg->win->win).x,
        sfRenderWindow_getSize(rpg->win->win).y});
    re_set_res_button_pos(rpg);
}
