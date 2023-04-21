/*
** EPITECH PROJECT, 2023
** end_fishing_game
** File description:
** end_fishing_game
*/

#include "rpg.h"

static bool fish_is_out_of_zone(fishing_t *game)
{
    if (game->fish->pos_fish.y > game->zone->pos_zone.y + 68)
        return (true);
    if (game->fish->pos_fish.y < game->zone->pos_zone.y - 68)
        return (true);
    return (false);
}

void end_game(fishing_t *game, win_t *win, rpg_t *rpg)
{
    game->info->clock_keep_time += win->deltaT;
    sfBool out = fish_is_out_of_zone(game);

    if (out ||
        game->info->clock_keep_time > game->info->game_time) {
        rpg->player->state = IDLE;
        game->info->game_state = false;
        game->fish->fish_moving = false;
        game->info->clock_game = 0;
        game->info->clock_keep_time = 0;
        game->info->game_start = 0;
        game->info->res_fishing = (out) ? -1 : 1;
        if (!out)
            add_res_to_quest(rpg->quests, "Peche");
    }
}
