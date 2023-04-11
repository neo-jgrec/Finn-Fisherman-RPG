/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** loading_screen
*/

#include "rpg.h"

void loading_screen(rpg_t *rpg, loading_t *loading,
    int pourcentage, int next)
{
    sprite_t sprite = loading->fishs[loading->fish];

    sfRenderWindow_clear(rpg->win->win, sfBlack);
    sfSprite_setPosition(sprite.sp,
        (VEC){1920 / 2, 1080 / 2});
    sfSprite_setTextureRect(sprite.sp,
        (sfIntRect){0, 0, pourcentage * sprite.size.x / 100,
        sprite.size.y});
    sfRenderWindow_drawSprite(rpg->win->win,
        sprite.sp, NULL);
    sfRenderWindow_display(rpg->win->win);
    sfSleep(sfSeconds(0.1));
    if (next == 1)
        loading->fish += 1;
    if (loading->fish == loading->nb_fish)
        loading->fish = 0;
}
