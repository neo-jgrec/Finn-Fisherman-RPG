/*
** EPITECH PROJECT, 2023
** array
** File description:
** main.c
*/

#include "array.h"

void** create_array(int nb_elements)
{
    void **array = malloc(sizeof(void*) * (nb_elements + 1));

    for (int i = 0; i < nb_elements; i++)
        array[i] = NULL;
    array[nb_elements] = NULL;
    return array;
}
