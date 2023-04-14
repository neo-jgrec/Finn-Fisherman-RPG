/*
** EPITECH PROJECT, 2023
** init_fishing
** File description:
** init_fishing
*/

#include "rpg.h"

static sfRectangleShape *init_rect_bar(rpg_t *rpg)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    if (rectangle == NULL)
        return (NULL);
    sfRectangleShape_setSize(rectangle, (sfVector2f){30, 100});
    sfRectangleShape_setPosition(rectangle, (sfVector2f){
    rpg->win->size.x / 2, rpg->win->size.y / 2});
    sfRectangleShape_setOrigin(rectangle, (sfVector2f){15, 50});
    sfRectangleShape_setFillColor(rectangle, sfGreen);
    return (rectangle);
}

static sprite_t init_fish(fishing_t *fishing)
{
    sprite_t fish = init_sprite("assets/fishing/fish.png",
    (sfVector2f){150, 100}, 1, 0.5);

    sfSprite_setOrigin(fish.sp, (sfVector2f){75, 50});
    sfSprite_setPosition(fish.sp, fishing->pos_fish);
    return (fish);
}

static sprite_t init_font(fishing_t *fishing)
{
    sprite_t font = init_sprite("assets/fishing/f_bar.png",
    (sfVector2f){60, 800}, 1, 1);

    sfSprite_setOrigin(font.sp, (sfVector2f){30, 400});
    sfSprite_setPosition(font.sp, fishing->pos_fish);
    return (font);
}

void init_fishing(rpg_t *rpg)
{
    fishing_t *fishing = NULL;

    if (!(fishing = malloc(sizeof(fishing_t)))) {
        rpg->fishing = NULL;
        return;
    }
    fishing->pos_fish = (sfVector2f){rpg->win->size.x / 2,
    rpg->win->size.y / 2};
    fishing->fish = init_fish(fishing);
    fishing->font = init_font(fishing);
    fishing->fish_bar = init_rect_bar(rpg);
    fishing->state = false;
    fishing->clock = 0;
    rpg->fishing = fishing;
}
