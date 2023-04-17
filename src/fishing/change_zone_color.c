/*
** EPITECH PROJECT, 2023
** change_zone_color
** File description:
** change_zone_color
*/

#include "rpg.h"

void change_zone_color(fishing_t *game)
{
    sfRectangleShape_setFillColor(game->zone->zone, sfGreen);
    if (game->fish->pos_fish.y > game->zone->pos_zone.y + 15)
        sfRectangleShape_setFillColor(game->zone->zone, sfLightGreen);
    if (game->fish->pos_fish.y < game->zone->pos_zone.y - 15)
        sfRectangleShape_setFillColor(game->zone->zone, sfLightGreen);
    if (game->fish->pos_fish.y > game->zone->pos_zone.y + 30)
        sfRectangleShape_setFillColor(game->zone->zone, sfYellow);
    if (game->fish->pos_fish.y < game->zone->pos_zone.y - 30)
        sfRectangleShape_setFillColor(game->zone->zone, sfYellow);
    if (game->fish->pos_fish.y > game->zone->pos_zone.y + 45)
        sfRectangleShape_setFillColor(game->zone->zone, sfOrange);
    if (game->fish->pos_fish.y < game->zone->pos_zone.y - 45)
        sfRectangleShape_setFillColor(game->zone->zone, sfOrange);
    if (game->fish->pos_fish.y > game->zone->pos_zone.y + 60)
        sfRectangleShape_setFillColor(game->zone->zone, sfRed);
    if (game->fish->pos_fish.y < game->zone->pos_zone.y - 60)
        sfRectangleShape_setFillColor(game->zone->zone, sfRed);
}
