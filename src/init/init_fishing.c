/*
** EPITECH PROJECT, 2023
** init_fishing
** File description:
** init_fishing
*/

#include "rpg.h"

static sfRectangleShape *init_rect_bar(rpg_t *rpg, fishing_t *game)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    if (rectangle == NULL)
        return (NULL);
    sfRectangleShape_setSize(rectangle, (sfVector2f){30, 100});
    sfRectangleShape_setPosition(rectangle, (sfVector2f){
    rpg->win->size.x / 2, rpg->win->size.y / 2});
    sfRectangleShape_setOrigin(rectangle, (sfVector2f){15, 50});
    sfRectangleShape_setFillColor(rectangle, sfGreen);
    game->bar_moving = false;
    game->clock_bar = 0;
    game->state_bar_moving = 0;
    game->time_move_bar = 0;
    return (rectangle);
}

static sprite_t init_fish(fishing_t *fishing)
{
    sprite_t fish = init_sprite("assets/fishing/fish.png",
    (sfVector2f){150, 100}, 1, 0.5);

    sfSprite_setOrigin(fish.sp, (sfVector2f){75, 50});
    sfSprite_setPosition(fish.sp, fishing->game_pos);
    return (fish);
}

static sprite_t init_font(fishing_t *fishing)
{
    sprite_t font = init_sprite("assets/fishing/f_bar.png",
    (sfVector2f){60, 800}, 1, 1);

    sfSprite_setOrigin(font.sp, (sfVector2f){30, 400});
    sfSprite_setPosition(font.sp, fishing->game_pos);
    return (font);
}

static void init_pos(fishing_t *fishing, rpg_t *rpg)
{
    fishing->game_pos = (sfVector2f){rpg->win->size.x / 2,
    rpg->win->size.y / 2};
    fishing->start_game_pos = fishing->game_pos;
    fishing->end_game_pos = fishing->game_pos;
    fishing->fish_zone_pos = fishing->game_pos;
    fishing->fish_pos = fishing->game_pos;
}

void init_fishing(rpg_t *rpg)
{
    fishing_t *fishing = NULL;

    if (!(fishing = malloc(sizeof(fishing_t)))) {
        rpg->fishing = NULL;
        return;
    }
    init_pos(fishing, rpg);
    fishing->fish = init_fish(fishing);
    fishing->font = init_font(fishing);
    fishing->fish_bar = init_rect_bar(rpg, fishing);
    fishing->state = false;
    fishing->clock_game = 0;
    fishing->clock_fish = 0;
    rpg->fishing = fishing;
}
