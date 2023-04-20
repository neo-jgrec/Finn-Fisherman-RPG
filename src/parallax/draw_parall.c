/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_parall
*/

#include "rpg.h"

static void draw_plus(win_t *win, parall_t *parall, int i)
{
    sfSprite_setPosition(parall->layers[i].sp,
        (VEC){parall->pos[i].x - parall->layers[i].size.x * 8,
            parall->pos[i].y});
    sfRenderWindow_drawSprite(win->win, parall->layers[i].sp, NULL);
    sfSprite_setPosition(parall->layers[i].sp,
        (VEC){parall->pos[i].x + parall->layers[i].size.x * 8,
            parall->pos[i].y});
    sfRenderWindow_drawSprite(win->win, parall->layers[i].sp, NULL);
}

void draw_parall(win_t *win, parall_t *parall)
{
    for (int i = 0; i < parall->nb; i++) {
        sfSprite_setPosition(parall->layers[i].sp, parall->pos[i]);
        sfRenderWindow_drawSprite(win->win, parall->layers[i].sp, NULL);
        sfSprite_setPosition(parall->layers[i].sp,
            (VEC){parall->pos[i].x + parall->layers[i].size.x * 4,
                parall->pos[i].y});
        sfRenderWindow_drawSprite(win->win, parall->layers[i].sp, NULL);
        sfSprite_setPosition(parall->layers[i].sp,
            (VEC){parall->pos[i].x - parall->layers[i].size.x * 4,
                parall->pos[i].y});
        sfRenderWindow_drawSprite(win->win, parall->layers[i].sp, NULL);
        draw_plus(win, parall, i);
    }
}
