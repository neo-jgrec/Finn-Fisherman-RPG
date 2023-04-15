/*
** EPITECH PROJECT, 2023
** end_fishing_game
** File description:
** end_fishing_game
*/

#include "rpg.h"

static bool fish_is_out_of_zone(fishing_t *game)
{
    if (game->fish_pos.y > game->fish_zone_pos.y + 68)
        return (true);
    if (game->fish_pos.y < game->fish_zone_pos.y - 68)
        return (true);
    return (false);
}

void end_game(fishing_t *game, win_t *win)
{
    game->clock_keep += win->deltaT;

    if (fish_is_out_of_zone(game)) {
        game->state = false;
        game->bar_moving = false;
        game->clock_game = 0;
        game->clock_keep = 0;
        game->res_fishing = -1;
        return;
    }
    if (game->fish_zone_pos.y <= game->end_game_pos.y ||
    game->clock_keep > 30) {
        game->state = false;
        game->bar_moving = false;
        game->clock_game = 0;
        game->clock_keep = 0;
        game->res_fishing = 1;
        return;
    }
}
