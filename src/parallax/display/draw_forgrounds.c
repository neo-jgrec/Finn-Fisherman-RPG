/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_forgrounds
*/

#include "rpg.h"

void draw_forgrounds(win_t *win, rpg_t *rpg)
{
    if (!rpg->font_cpy->is_moved)
        set_cpy_pos(win, rpg);
    for (ssize_t i = 2; i >= 0; i--) {
        sfRenderWindow_drawSprite(win->win,
        rpg->font->layrs_sprites[i].sp, NULL);
    }
    for (ssize_t i = 2; i >= 0; i--) {
        sfRenderWindow_drawSprite(win->win,
        rpg->font_cpy->layrs_sprites[i].sp, NULL);
    }
    return;
}
