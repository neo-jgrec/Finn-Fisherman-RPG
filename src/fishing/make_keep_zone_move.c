/*
** EPITECH PROJECT, 2023
** make_keep_zone_move
** File description:
** make_keep_zone_move
*/

#include "rpg.h"

static void move_down(fishing_t *game, win_t *win)
{
    game->zone->clock_zone += win->deltaT;

    if (game->zone->clock_zone < game->zone->time_move_zone){
        game->zone->pos_zone.y += game->zone->speed_zone;
        if (game->zone->pos_zone.y > game->font->pos_bot.y)
            game->zone->pos_zone.y = game->font->pos_bot.y;
    } else {
        game->zone->clock_zone = 0;
        game->zone->zone_moving = false;
        game->zone->time_move_zone = 0;
        game->zone->direction_zone = 0;
    }
}

static void move_up(fishing_t *game, win_t *win)
{
    game->zone->clock_zone += win->deltaT;

    if (game->zone->clock_zone < game->zone->time_move_zone){
        game->zone->pos_zone.y -= game->zone->speed_zone;
        if (game->zone->pos_zone.y < game->font->pos_top.y)
            game->zone->pos_zone.y = game->font->pos_top.y;
    } else {
        game->zone->clock_zone = 0;
        game->zone->zone_moving = false;
        game->zone->time_move_zone = 0;
        game->zone->direction_zone = 0;
    }
}

static void make_random_move(fishing_t *game, win_t *win)
{
    if (!game->zone->zone_moving) {
        game->zone->direction_zone = (rand() % 2) + 1;
        game->zone->time_move_zone = (rand() % 1) + 1;
        game->zone->zone_moving = true;
    }
    if (game->zone->direction_zone == 2)
        move_down(game, win);
    else
        move_up(game, win);
    sfRectangleShape_setPosition(game->zone->zone, game->zone->pos_zone);
}

void make_keep_zone_move(win_t *win, fishing_t *game)
{
    game->info->clock_game += win->deltaT;
    if (game->info->clock_game > 0.02)
        make_random_move(game, win);
}
