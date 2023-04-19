/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** handle_left_parallax
*/

#include "rpg.h"

static void manage_positions_left(rpg_t *rpg, parallax_t *font,
parallax_t *cpy, size_t i)
{
    if (PLAY_POSX + (WIN_SX / 2) <= LAY_POSX - (LAY_SX / 2 * LAY_SCALX)) {
        sfSprite_setPosition(font->layrs_sprites[i].sp,
        (VEC){CPY_POSX - (CPY_SX * CPY_SCALX), cpy->pos_y});
        font->pos_x[i] = CPY_POSX - (CPY_SX * CPY_SCALX);
    } else {
        sfSprite_setPosition(font->layrs_sprites[i].sp,
        (VEC){font->pos_x[i] + font->layers_speed[i], font->pos_y});
        font->pos_x[i] = font->pos_x[i] + font->layers_speed[i];
    }
    if (PLAY_POSX + (WIN_SX / 2) <= CPY_POSX - (CPY_SX / 2 * CPY_SCALX)) {
        sfSprite_setPosition(cpy->layrs_sprites[i].sp,
        (VEC){LAY_POSX - (LAY_SX * LAY_SCALX), font->pos_y});
        cpy->pos_x[i] = LAY_POSX - (LAY_SX * LAY_SCALX);
    } else {
        sfSprite_setPosition(cpy->layrs_sprites[i].sp,
        (VEC){cpy->pos_x[i] + cpy->layers_speed[i], font->pos_y});
        cpy->pos_x[i] = cpy->pos_x[i] + font->layers_speed[i];
    }
    return;
}

void handle_left_parallax(rpg_t *rpg)
{
    for (size_t i = 0; i < rpg->font->nb_files; i++) {
        manage_positions_left(rpg, rpg->font, rpg->font_cpy, i);
    }
    return;
}
