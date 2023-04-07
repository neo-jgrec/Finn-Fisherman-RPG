/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_puzzle
*/
#include "rpg.h"

static sfFloatRect *init_colliders(void)
{
    sfFloatRect *colliders = malloc(sizeof(sfFloatRect) * 12);

    if (colliders == NULL)
        return NULL;
    colliders[0] = (sfFloatRect){0, 700, 1900, 100};
    return colliders;
}

void init_puzzle(rpg_t *rpg)
{
    puzzle_t *puzzle = malloc(sizeof(puzzle_t));

    if (puzzle == NULL)
        rpg->puzzle = NULL;
    puzzle->nb_colliders = 0;
    puzzle->colliders = NULL;
    puzzle->nb_colliders = 1;
    puzzle->colliders = init_colliders();
    rpg->puzzle = puzzle;
    loading_screen(rpg, rpg->loading, 40, 1);

}
