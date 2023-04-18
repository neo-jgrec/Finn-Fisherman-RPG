/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_parallax
*/

#include <sys/types.h>
#include "rpg.h"

void draw_forground(win_t *win, rpg_t *rpg)
{
    for (ssize_t i = 2; i >= 0; i--) {
        sfRenderWindow_drawSprite(win->win,
        rpg->font->layrs_sprites[i].sp, NULL);
    }
    return;
}

void draw_background(win_t *win, rpg_t *rpg)
{
    for (size_t i = rpg->font->nb_files - 1; i > 3; i--) {
        sfRenderWindow_drawSprite(win->win,
        rpg->font->layrs_sprites[i].sp, NULL);
    }
    return;
}
