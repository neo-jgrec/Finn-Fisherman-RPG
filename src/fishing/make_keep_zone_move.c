/*
** EPITECH PROJECT, 2023
** make_keep_zone_move
** File description:
** make_keep_zone_move
*/

#include "rpg.h"

static void move_zone_up(fishing_t *game)
{
    game->zone->pos_zone.y -= game->zone->speed_zone * 60;
    if (game->zone->pos_zone.y < game->font->pos_top.y)
        game->zone->pos_zone.y = game->font->pos_top.y;
}

static void move_zone_down(fishing_t *game)
{
    game->zone->pos_zone.y += game->zone->speed_zone * 60;
    if (game->zone->pos_zone.y > game->font->pos_bot.y)
        game->zone->pos_zone.y = game->font->pos_bot.y;
}

void make_keep_zone_move(rpg_t *rpg, fishing_t *game)
{
    if (rpg->input->fish_up.press)
        move_zone_up(game);
    if (rpg->input->fish_down.press)
        move_zone_down(game);
    sfRectangleShape_setPosition(game->zone->zone, game->zone->pos_zone);
}
