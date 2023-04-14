/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_map
*/

#include "rpg.h"

static void draw_tiles(win_t *win, sprite_t *sp, int **map, int i)
{
    for (int j = 0; map[i][j] != -2; j++) {
        if (map[i][j] != -1) {
            sfSprite_setTextureRect(sp->sp,
                (sfIntRect){sp->size.x * (map[i][j] % sp->nb_frame),
                    sp->size.x * (map[i][j] / sp->nb_frame),
                    sp->size.x, sp->size.x});
            sfSprite_setPosition(sp->sp, (VEC){j * 64, i * 64});
            sfRenderWindow_drawSprite(win->win, sp->sp, NULL);
        }
    }
}

void draw_map(win_t *win, puzzle_t *puzzle, int **map)
{
    sprite_t *sp = puzzle->tileset;

    for (int i = 0; map[i] != NULL; i++)
        draw_tiles(win, sp, map, i);
}
