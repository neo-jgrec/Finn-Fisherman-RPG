/*
** EPITECH PROJECT, 2023
** array
** File description:
** add_element
*/

#include "array.h"

void **add_element_head(void **array, void *element)
{
    void **new_array;

    if (array == NULL) {
        write(2, "Array is NULL: add_element_head\n", 32);
        write(2, "Creating a new array\n", 21);
        new_array = create_array(1);
        new_array[0] = element;
        return new_array;
    }
    new_array = create_array(get_array_size(array) + 1);
    new_array[0] = element;
    for (int i = 0; array[i] != NULL; i++)
        new_array[i + 1] = array[i];
    free(array);
    return new_array;
}

void **add_element_tail(void **array, void *element)
{
    void **new_array;

    if (array == NULL) {
        write(2, "Array is NULL: add_element_head\n", 32);
        write(2, "Creating a new array\n", 21);
        new_array = create_array(1);
        new_array[0] = element;
        return new_array;
    }
    new_array = create_array(get_array_size(array) + 1);
    for (int i = 0; array[i] != NULL; i++)
        new_array[i] = array[i];
    new_array[get_array_size(array)] = element;
    free(array);
    return new_array;
}

void **insert_element_at_index(void **array, void *element, int index)
{
    void **new_array = create_array(get_array_size(array) + 1);

    for (int i = 0; i < index; i++)
        new_array[i] = array[i];
    new_array[index] = element;
    for (int i = index; array[i] != NULL; i++)
        new_array[i + 1] = array[i];
    free(array);
    return new_array;
}
