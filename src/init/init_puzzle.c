/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_puzzle
*/

#include "rpg.h"

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
    sfFloatRect *colliders = NULL;

    for (int i = 0; map[i] != NULL; i++)
        merge_colliders(&colliders, nb_col, map, i);
    return colliders;
}

static void init_null(puzzle_t *puzzle)
{
    puzzle->colliders = NULL;
    puzzle->death = NULL;
    puzzle->fish_spot = NULL;
    puzzle->sign = NULL;
    puzzle->nb_sign = 0;
    puzzle->nb_colliders = 0;
    puzzle->nb_colliders = 0;
    puzzle->nb_fish_spot = 0;
    puzzle->nb_spikes = 0;
    puzzle->spawn = (VEC){0};
}

static void set_tileset(rpg_t *rpg, puzzle_t *puzzle)
{
    puzzle->tileset = &rpg->asset->tileset;
}

void init_puzzle(rpg_t *rpg)
{
    puzzle_t *puzzle = malloc(sizeof(puzzle_t));

    if (puzzle == NULL)
        rpg->puzzle = NULL;
    puzzle->parser = init_parser((char *)map_list[rpg->data->location]);
    parse_xml(puzzle->parser);
    init_null(puzzle);
    init_map(puzzle);
    puzzle->colliders = init_colliders(&puzzle->nb_colliders, puzzle->map);
    puzzle->spikes = init_colliders(&puzzle->nb_spikes, puzzle->death);
    set_tileset(rpg, puzzle);
    rpg->player->pos = puzzle->spawn;
    rpg->puzzle = puzzle;
    loading_screen(rpg, rpg->loading, 40, 0);
}
