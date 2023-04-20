/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_button_hud
*/

#include "rpg.h"

void draw_button_hud(entity_t *player, rpg_t *rpg)
{
    if ((player->health.on_fish_spot && player->state != FISHING) ||
        player->health.interaction_zone || player->health.sign) {
        sfSprite_setPosition(player->health.button_f.sp,
            (VEC){player->pos.x, player->pos.y - 56});
        sfRenderWindow_drawSprite(rpg->win->win,
            player->health.button_f.sp, NULL);
    }
}
