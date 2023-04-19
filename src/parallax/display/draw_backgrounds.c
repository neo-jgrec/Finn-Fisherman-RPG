/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** draw_backgrounds
*/

#include "rpg.h"

void draw_backgrounds(win_t *win, rpg_t *rpg)
{
    if (!rpg->font_cpy->is_moved)
        set_cpy_pos(win, rpg);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        handle_right_parallax(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        handle_left_parallax(rpg);
    for (size_t i = rpg->font->nb_files - 1; i > 3; i--) {
        sfRenderWindow_drawSprite(win->win,
        rpg->font->layrs_sprites[i].sp, NULL);
    }
    for (size_t i = rpg->font->nb_files - 1; i > 3; i--) {
        sfRenderWindow_drawSprite(win->win,
        rpg->font_cpy->layrs_sprites[i].sp, NULL);
    }
    return;
}
