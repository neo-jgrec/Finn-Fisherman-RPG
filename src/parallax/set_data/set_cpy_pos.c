/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_cpy_pos
*/

#include "rpg.h"

static void set_basic_pos(rpg_t *rpg)
{
    VEC pos = (VEC){rpg->player->pos.x, rpg->font->pos_y};
    for (size_t i = 0; i < rpg->font->nb_files; i++) {
        rpg->font->pos_x[i] = pos.x;
        sfSprite_setPosition(rpg->font->layrs_sprites[i].sp, pos);
    }
    return;
}

void set_cpy_pos(UNUSED win_t *win, rpg_t *rpg)
{
    VEC new_pos;

    new_pos = (VEC){PLAY_POSX + (rpg->LAY_SX * rpg->LAY_SCALX),
    rpg->font->pos_y};
    set_basic_pos(rpg);
    for (size_t i = 0; i < rpg->font->nb_files; i++) {
        rpg->font_cpy->pos_x[i] = new_pos.x;
        sfSprite_setPosition(rpg->font_cpy->layrs_sprites[i].sp, new_pos);
    }
    rpg->font_cpy->is_moved = true;
    return;
}
