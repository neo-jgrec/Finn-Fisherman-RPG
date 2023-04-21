/*
** EPITECH PROJECT, 2023
** init_fishing
** File description:
** init_fishing
*/

#include "rpg.h"
#include <assert.h>

static zone_t *init_zone(fishing_t *game)
{
    zone_t *zone = malloc(sizeof(zone_t));

    if (!zone || !game->font)
        return (NULL);
    zone->zone = sfRectangleShape_create();
    if (!zone->zone)
        return (NULL);
    zone->pos_zone = game->font->pos_font;
    sfRectangleShape_setSize(zone->zone, (sfVector2f){30, 100});
    sfRectangleShape_setPosition(zone->zone, zone->pos_zone);
    sfRectangleShape_setOrigin(zone->zone, (sfVector2f){15, 50});
    sfRectangleShape_setFillColor(zone->zone, sfGreen);
    zone->speed_zone = 0;
    return (zone);
}

static fish_t *init_fish(fishing_t *game)
{
    fish_t *fish = malloc(sizeof(fish_t));


    if (!fish || !game->font)
        return (NULL);
    fish->fish = init_sprite("assets/fishing/fish.png",
    (sfVector2f){150, 100}, 1, 0.5);
    fish->pos_fish = game->font->pos_font;
    sfSprite_setOrigin(fish->fish.sp, (sfVector2f){75, 50});
    sfSprite_setPosition(fish->fish.sp, game->font->pos_font);
    fish->fish_moving = false;
    fish->time_move_fish = 0;
    fish->direction_fish = 0;
    fish->clock_fish = 0;
    fish->speed_fish = 0;
    return (fish);
}

static font_t *init_font(void)
{
    font_t *font = malloc(sizeof(font_t));

    if (!font)
        return (NULL);
    font->font = init_sprite("assets/fishing/f_bar.png",
    (sfVector2f){60, 800}, 1, 1);
    font->pos_font = (sfVector2f){0, 0};
    sfSprite_setOrigin(font->font.sp, (sfVector2f){30, 400});
    sfSprite_setPosition(font->font.sp, font->pos_font);
    font->pos_bot = font->pos_font;
    font->pos_top = font->pos_font;
    return (font);
}

static game_info_t *init_game_info(void)
{
    game_info_t *game = malloc(sizeof(game_info_t));

    if (!game)
        return (NULL);
    game->clock_keep_time = 0;
    game->game_state = false;
    game->game_time = 0;
    game->res_fishing = 0;
    game->game_start = 0;
    return (game);
}

void init_fishing(rpg_t *rpg)
{
    fishing_t *game = malloc(sizeof(fishing_t));

    rpg->fishing = NULL;
    if (!game)
        return;
    game->info = init_game_info();
    game->font = init_font();
    game->fish = init_fish(game);
    game->zone = init_zone(game);
    rpg->fishing = game;
}
