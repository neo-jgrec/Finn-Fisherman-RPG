/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** free_puzzle
*/

#include "rpg.h"

static void free_map(int **map)
{
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

void free_puzzle(puzzle_t *puzzle)
{
    free_map(puzzle->background);
    free_map(puzzle->foreground);
    free_map(puzzle->death);
    free_map(puzzle->map);
    free(puzzle->sign);
    free(puzzle->colliders);
    free(puzzle->spikes);
    free(puzzle->fish_spot);
    free_parser(puzzle->parser);
    free(puzzle);
}
