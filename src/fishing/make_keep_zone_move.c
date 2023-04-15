/*
** EPITECH PROJECT, 2023
** make_keep_zone_move
** File description:
** make_keep_zone_move
*/

#include "rpg.h"

static void move_down(fishing_t *game, win_t *win)
{
    game->clock_bar += win->deltaT;

    if (game->clock_bar < game->time_move_bar){
        game->fish_zone_pos.y += game->speed_mov;
        if (game->fish_zone_pos.y > game->start_game_pos.y)
            game->fish_zone_pos.y = game->start_game_pos.y;
    } else {
        game->clock_bar = 0;
        game->bar_moving = false;
        game->time_move_bar = 0;
        game->state_bar_moving = 0;
    }
}

static void move_up(fishing_t *game, win_t *win)
{
    game->clock_bar += win->deltaT;

    if (game->clock_bar < game->time_move_bar){
        game->fish_zone_pos.y -= game->speed_mov;
        if (game->fish_zone_pos.y < game->end_game_pos.y)
            game->fish_zone_pos.y = game->end_game_pos.y;
    } else {
        game->clock_bar = 0;
        game->bar_moving = false;
        game->time_move_bar = 0;
        game->state_bar_moving = 0;
    }
}

static void make_random_move(fishing_t *game, win_t *win)
{
    if (game->bar_moving == false) {
        game->state_bar_moving = (rand() % 3) + 1;
        game->time_move_bar = (rand() % 1) + 1;
        game->bar_moving = true;
    }
    if (game->state_bar_moving == 2)
        move_down(game, win);
    else
        move_up(game, win);
    sfRectangleShape_setPosition(game->fish_bar, game->fish_zone_pos);
}

void make_keep_zone_move(win_t *win, fishing_t *game)
{
    game->clock_game += win->deltaT;
    if (game->clock_game > 0.02)
        make_random_move(game, win);
}
