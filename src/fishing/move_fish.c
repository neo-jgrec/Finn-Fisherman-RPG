/*
** EPITECH PROJECT, 2023
** move_fish
** File description:
** move_fish
*/

#include "rpg.h"

static void move_fish_up(win_t * win, fishing_t *game)
{
    game->clock_fish += win->deltaT;

    if (game->clock_fish > 0.002){
        game->fish_pos.y -= 1.5;
        if (game->fish_pos.y < game->end_game_pos.y)
            game->fish_pos.y = game->end_game_pos.y;
        sfSprite_setPosition(game->fish.sp, game->fish_pos);
        game->clock_fish = 0;
    }
}

static void move_fish_down(win_t * win, fishing_t *game)
{
    game->clock_fish += win->deltaT;

    if (game->clock_fish > 0.002){
        game->fish_pos.y += 1.5;
        if (game->fish_pos.y > game->start_game_pos.y)
            game->fish_pos.y = game->start_game_pos.y;
        sfSprite_setPosition(game->fish.sp, game->fish_pos);
        game->clock_fish = 0;
    }
}

void make_fish_move(rpg_t *rpg, fishing_t *game)
{
    if (rpg->input->fish_up.press)
        move_fish_up(rpg->win, game);
    if (rpg->input->fish_down.press)
        move_fish_down(rpg->win, game);
}
