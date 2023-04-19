/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_layer_speed
*/

#include "rpg.h"

void set_layer_speed(parallax_t *back)
{
    size_t multiplicator = NB_FILES / 2;

    if (FILEPATHS == NULL)
        return;
    back->layers_speed = malloc(sizeof(size_t) * NB_FILES);
    if (back->layers_speed == NULL)
        return;
    for (size_t i = 0; i < NB_FILES; i++) {
        back->layers_speed[i] = multiplicator;
        multiplicator -= 0.5;
    }
    return;
}
