/*
** EPITECH PROJECT, 2023
** array
** File description:
** print_array
*/

#include "array.h"

void print_array(void **array, void (*print_function)(void*))
{
    if (print_function == NULL) {
        write(2, "Print function is NULL: print_array\n", 36);
        return;
    }
    for (int i = 0; i < get_array_size(array); i++)
        print_function(array[i]);
}
