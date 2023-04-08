/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** get_collision
*/

#include "rpg.h"

sfFloatRect *add_colliders(sfFloatRect *colliders,
    sfFloatRect rect, int *nb_col)
{
    sfFloatRect *new = NULL;

    new = malloc(sizeof(sfFloatRect) * (*nb_col + 1));
    if (new == NULL)
        return NULL;
    for (int i = 0; i < *nb_col + 1; new[i] = (sfFloatRect){0}, i++);
    for (int i = 0; i < *nb_col; i++)
        new[i] = colliders[i];
    new[*nb_col] = rect;
    *nb_col += 1;
    free(colliders);
    return new;
}
