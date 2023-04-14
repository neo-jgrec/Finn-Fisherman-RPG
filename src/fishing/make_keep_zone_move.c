/*
** EPITECH PROJECT, 2023
** make_keep_zone_move
** File description:
** make_keep_zone_move
*/

#include "rpg.h"

void make_keep_zone_move(win_t *win, fishing_t *game)
{
    game->clock += win->deltaT;
    if (game->clock > 0.02){
        game->fish_zone_pos.y -= 2;
        sfRectangleShape_setPosition(game->fish_bar, game->fish_zone_pos);
        game->clock = 0;
    }
}
