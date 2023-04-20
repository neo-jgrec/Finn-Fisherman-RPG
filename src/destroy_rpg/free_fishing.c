/*
** EPITECH PROJECT, 2023
** free_fishing
** File description:
** free_fishing
*/

#include "rpg.h"

static void free_zone(zone_t *zone)
{
    sfRectangleShape_destroy(zone->zone);
    free(zone);
}

static void free_fish(fish_t *fish)
{
    sfSprite_destroy(fish->fish.sp);
    sfTexture_destroy(fish->fish.tx);
    free(fish);
}

static void free_font(font_t *font)
{
    sfSprite_destroy(font->font.sp);
    sfTexture_destroy(font->font.tx);
    free(font);
}

void free_fishing(rpg_t *rpg)
{
    if (rpg->fishing) {
        if (rpg->fishing->info)
            free(rpg->fishing->info);
        if (rpg->fishing->font)
            free_font(rpg->fishing->font);
        if (rpg->fishing->zone)
            free_zone(rpg->fishing->zone);
        if (rpg->fishing->fish)
            free_fish(rpg->fishing->fish);
        free(rpg->fishing);
    }
}
