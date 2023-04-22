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

static void fish_result(sfBool out, rpg_t *rpg)
{
    int list_item_drop[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    if (!out) {
        add_res_to_quest(rpg->quests, "Peche");
        add_info_text(rpg, sfYellow,
            (VEC){rpg->player->pos.x, rpg->player->pos.y - 50},
                my_strdup("CATCH"));
        add_item(rpg, 2,
            (VEC){rpg->player->pos.x - 50,
            rpg->player->pos.y});
    } else {
        add_info_text(rpg, sfBlue,
        (VEC){rpg->player->pos.x, rpg->player->pos.y - 50},
            my_strdup("miss"));
    }
}

void end_game(fishing_t *game, win_t *win, rpg_t *rpg)
{
    game->info->clock_keep_time += win->deltaT;
    sfBool out = fish_is_out_of_zone(game);
    
    if (rpg->player->state != FISHING)
        out = sfTrue;
    if (out ||
        game->info->clock_keep_time > game->info->game_time) {
        rpg->player->state = IDLE;
        game->info->game_state = false;
        game->fish->fish_moving = false;
        game->info->clock_keep_time = 0;
        game->info->game_start = 0;
        game->info->res_fishing = (out) ? -1 : 1;
        fish_result(out, rpg);
    }
}
