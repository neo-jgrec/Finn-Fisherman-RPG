/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_puzzle
*/

#include "rpg.h"

static sfFloatRect *add_colliders(sfFloatRect *colliders,
    sfFloatRect rect, int *nb_col)
{
    sfFloatRect *new = NULL;

    new = malloc(sizeof(sfFloatRect) * (*nb_col + 2));
    if (new == NULL)
        return NULL;
    for (int i = 0; i < *nb_col + 2; new[i] = (sfFloatRect){0}, i++);
    for (int i = 0; i < *nb_col; i++)
        new[i] = colliders[i];
    new[*nb_col] = rect;
    *nb_col += 1;
    free(colliders);
    return new;
}

static void merge_colliders(sfFloatRect **colliders,
    int *nb_col, int **map, int i)
{
    for (int j = 0; map[i][j] != -2; j++) {
        if (map[i][j] != -1)
            *colliders = add_colliders(*colliders,
                (sfFloatRect){j * 64, i * 64, 64, 64}, nb_col);
    }
}

static sfFloatRect *init_colliders(int *nb_col, int **map)
{
    sfFloatRect *colliders = malloc(sizeof(sfFloatRect) * 2);

    if (colliders == NULL)
        return NULL;
    colliders[0] = (sfFloatRect){0};
    colliders[1] = (sfFloatRect){0};
    for (int i = 0; map[i] != NULL; i++) {
        merge_colliders(&colliders, nb_col, map, i);
    }
    return colliders;
}

void init_puzzle(rpg_t *rpg)
{
    puzzle_t *puzzle = malloc(sizeof(puzzle_t));

    if (puzzle == NULL)
        rpg->puzzle = NULL;
    puzzle->spawn = (VEC){500, 400};
    puzzle->nb_colliders = 0;
    puzzle->colliders = NULL;
    puzzle->nb_colliders = 0;
    init_map("assets/map/map_1.xml", puzzle);
    puzzle->colliders = init_colliders(&puzzle->nb_colliders, puzzle->map);
    puzzle->tileset = &rpg->asset->tileset;
    rpg->player->pos = puzzle->spawn;
    rpg->puzzle = puzzle;
    loading_screen(rpg, rpg->loading, 40, 0);
}
