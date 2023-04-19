/*
** EPITECH PROJECT, 2023
** move_fish
** File description:
** move_fish
*/

#include "rpg.h"

static void move_down(fishing_t *game, win_t *win)
{
    game->fish->clock_fish += win->deltaT;

    if (game->fish->clock_fish < game->fish->time_move_fish){
        game->fish->pos_fish.y += game->fish->speed_fish;
        if (game->fish->pos_fish.y > game->font->pos_bot.y)
            game->fish->pos_fish.y = game->font->pos_bot.y;
    } else {
        game->fish->clock_fish = 0;
        game->fish->fish_moving = false;
        game->fish->time_move_fish = 0;
        game->fish->direction_fish = 0;
    }
}

static void move_up(fishing_t *game, win_t *win)
{
    game->fish->clock_fish += win->deltaT;

    if (game->fish->clock_fish < game->fish->time_move_fish){
        game->fish->pos_fish.y -= game->fish->speed_fish;
        if (game->fish->pos_fish.y < game->font->pos_top.y)
            game->fish->pos_fish.y = game->font->pos_top.y;
    } else {
        game->fish->clock_fish = 0;
        game->fish->fish_moving = false;
        game->fish->time_move_fish = 0;
        game->fish->direction_fish = 0;
    }
}

static void make_random_move(fishing_t *game, win_t *win)
{
    if (!game->fish->fish_moving) {
        game->fish->direction_fish = (rand() % 2) + 1;
        game->fish->time_move_fish = (rand() % 1) + 1;
        game->fish->fish_moving = true;
    }
    if (game->fish->direction_fish == 2)
        move_down(game, win);
    else
        move_up(game, win);
    sfSprite_setPosition(game->fish->fish.sp, game->fish->pos_fish);
}

void make_fish_move(win_t *win, fishing_t *game)
{
    game->info->clock_game += win->deltaT;
    if (game->info->clock_game > 0.02)
        make_random_move(game, win);
}
