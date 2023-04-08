/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_map
*/

#include "rpg.h"

void draw_map(win_t *win, puzzle_t *puzzle)
{
    sprite_t *sp = puzzle->tileset;
    int **map = puzzle->map;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != -1; j++) {
            sfSprite_setTextureRect(sp->sp,
                (sfIntRect){sp->size.x * (map[i][j] % sp->nb_frame),
                    sp->size.x * (map[i][j] / sp->nb_frame),
                    sp->size.x, sp->size.x});
            sfSprite_setPosition(sp->sp, (VEC){i * 64, j * 64});
            sfRenderWindow_drawSprite(win->win, sp->sp, NULL);
        }
    }
}
