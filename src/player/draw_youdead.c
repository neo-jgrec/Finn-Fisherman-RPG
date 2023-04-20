/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_youdead
*/

#include "rpg.h"

void youdead(rpg_t *rpg, loading_t *loading, int a)
{
    win_t *win = rpg->win;
    const sfView *view = sfRenderWindow_getView(rpg->win->win);

    if (a > 209)
        a = 209;
    sfSprite_setPosition(loading->youdead.sp,
        sfView_getCenter(view));
    sfSprite_setColor(loading->youdead.sp,
        sfColor_fromRGBA(255, 255, 255, a));
    sfRenderWindow_clear(win->win, sfBlack);
    draw_parall(win, rpg->parall);
    draw_map(win, rpg->puzzle, rpg->puzzle->background);
    draw_map(win, rpg->puzzle, rpg->puzzle->death);
    draw_monsters(rpg);
    draw_map(win, rpg->puzzle, rpg->puzzle->map);
    draw_map(win, rpg->puzzle, rpg->puzzle->map);
    draw_map(win, rpg->puzzle, rpg->puzzle->foreground);
    sfRenderWindow_drawSprite(win->win, loading->youdead.sp, NULL);
    sfRenderWindow_drawSprite(win->win, rpg->player->sp, NULL);
    sfRenderWindow_display(win->win);
}
