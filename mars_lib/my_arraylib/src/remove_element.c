/*
** EPITECH PROJECT, 2023
** array
** File description:
** remove_element
*/

#include "array.h"

void **remove_at_index(void **array, int index)
{
    void **new_array;

    if (index >= get_array_size(array) || index < 0 || array == NULL) {
        write(2, "Index out of range: remove_at_index\n", 36);
        return array;
    }
    new_array = create_array(get_array_size(array) - 1);
    for (int i = 0; i < index; i++)
        new_array[i] = array[i];
    for (int i = index; array[i + 1] != NULL; i++)
        new_array[i] = array[i + 1];
    free(array);
    return new_array;
}

void **remove_element(void **array, int index)
{
    void **new_array = create_array(get_array_size(array));

    if (index >= get_array_size(array) || index < 0) {
        write(2, "Index out of range: remove_element\n", 35);
        return array;
    }
    for (int i = 0; i < index; i++)
        new_array[i] = array[i];
    for (int i = index; array[i + 1] != NULL; i++)
        new_array[i] = array[i + 1];
    free(array);
    return new_array;
}
