/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw
*/

#include "rpg.h"

void draw(win_t *win, rpg_t *rpg)
{
    sfRenderWindow_drawSprite(win->win, rpg->asset->player.sp, NULL);
    draw_map(win, rpg->puzzle);
    sfRenderWindow_display(win->win);
}
