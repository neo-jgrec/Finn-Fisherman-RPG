/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_puzzle
*/

#include "rpg.h"

static int **init_map(void)
{
    int **map = malloc(sizeof(int *) * 25);
    for (int i = 0; i < 25; map[i] = NULL, i++);
    for (int i = 0; i < 20; i++) {
        map[i] = malloc(sizeof(int) * 25);
        for (int j = 0; j < 25; map[i][j] = -1, j++);
        for (int j = 0; j < 20; map[i][j] = 0, j++);
    }
    map[10][15] = 1;
    return map;
}

static sfFloatRect *init_colliders(void)
{
    sfFloatRect *colliders = malloc(sizeof(sfFloatRect) * 12);

    if (colliders == NULL)
        return NULL;
    colliders[0] = (sfFloatRect){0, 700, 1900, 100};
    colliders[1] = (sfFloatRect){800, 000, 10, 1000};
    return colliders;
}

void init_puzzle(rpg_t *rpg)
{
    puzzle_t *puzzle = malloc(sizeof(puzzle_t));

    if (puzzle == NULL)
        rpg->puzzle = NULL;
    puzzle->nb_colliders = 0;
    puzzle->colliders = NULL;
    puzzle->nb_colliders = 2;
    puzzle->colliders = init_colliders();
    puzzle->map = init_map();
    puzzle->tileset = &rpg->asset->tileset;
    rpg->puzzle = puzzle;
    loading_screen(rpg, rpg->loading, 40, 1);

}
