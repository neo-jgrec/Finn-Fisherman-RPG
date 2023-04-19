/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** functions_settings
*/

#include "rpg.h"
#include "mars.h"

void back_button(rpg_t *rpg)
{
    rpg->menu->scene = MAIN_MENU;
}

static void re_set_res_button_pos(rpg_t *rpg)
{
    button_t *button;

    TAILQ_FOREACH(button, &rpg->menu->res_buttons, next) {
        button->pos = (sfVector2f){\
        sfRenderWindow_getSize(rpg->win->win).x - 210, button->pos.y};
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

void sound_button(rpg_t *rpg)
{
    button_t *button;

    rpg->sound_volume = (rpg->sound_volume + 10 > 100)
    ? 0 : rpg->sound_volume + 10;
    TAILQ_FOREACH(button, &rpg->menu->settings_buttons, next) {
        if (my_strncmp(button->name, "SOUND", 5) == 0) {
            button->name = my_strcat_inf(3, "SOUND - ",
                my_itoa(rpg->sound_volume), "%");
        }
    }
}

void music_button(rpg_t *rpg)
{
    button_t *button;

    rpg->music_volume = (rpg->music_volume + 10 > 100)
    ? 0 : rpg->music_volume + 10;
    TAILQ_FOREACH(button, &rpg->menu->settings_buttons, next) {
        if (my_strncmp(button->name, "MUSIC", 5) == 0) {
            button->name = my_strcat_inf(3, "MUSIC - ",
                my_itoa(rpg->music_volume), "%");
        }
    }
}
