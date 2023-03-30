/*
** EPITECH PROJECT, 2023
** array
** File description:
** manage_array
*/

#include "array.h"

void **reverse_array(void **array)
{
    void **new_array;

    if (array == NULL) {
        write(2, "Array is NULL: reverse_array\n", 29);
        return NULL;
    }
    new_array = create_array(get_array_size(array));
    for (int i = 0; array[i] != NULL; i++)
        new_array[i] = array[get_array_size(array) - i - 1];
    free(array);
    return new_array;
}

void **copy_array(void **array)
{
    void **new_array;

    if (array == NULL) {
        write(2, "Array is NULL: copy_array\n", 26);
        return NULL;
    }
    new_array = create_array(get_array_size(array));
    for (int i = 0; array[i] != NULL; i++)
        new_array[i] = array[i];
    return new_array;
}
