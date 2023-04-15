/*
** EPITECH PROJECT, 2023
** change_zone_color
** File description:
** change_zone_color
*/

#include "rpg.h"

void change_zone_color(fishing_t *game)
{
    sfRectangleShape_setFillColor(game->fish_bar, sfGreen);
    if (game->fish_pos.y > game->fish_zone_pos.y + 15)
        sfRectangleShape_setFillColor(game->fish_bar, sfLightGreen);
    if (game->fish_pos.y < game->fish_zone_pos.y - 15)
        sfRectangleShape_setFillColor(game->fish_bar, sfLightGreen);
    if (game->fish_pos.y > game->fish_zone_pos.y + 30)
        sfRectangleShape_setFillColor(game->fish_bar, sfYellow);
    if (game->fish_pos.y < game->fish_zone_pos.y - 30)
        sfRectangleShape_setFillColor(game->fish_bar, sfYellow);
    if (game->fish_pos.y > game->fish_zone_pos.y + 45)
        sfRectangleShape_setFillColor(game->fish_bar, sfOrange);
    if (game->fish_pos.y < game->fish_zone_pos.y - 45)
        sfRectangleShape_setFillColor(game->fish_bar, sfOrange);
    if (game->fish_pos.y > game->fish_zone_pos.y + 60)
        sfRectangleShape_setFillColor(game->fish_bar, sfRed);
    if (game->fish_pos.y < game->fish_zone_pos.y - 60)
        sfRectangleShape_setFillColor(game->fish_bar, sfRed);
}
