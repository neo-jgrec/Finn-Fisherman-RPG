/*
** EPITECH PROJECT, 2023
** array
** File description:
** get_info
*/

#include "array.h"

int get_array_size(void **array)
{
    int nb_elements = 0;

    if (array == NULL)
        return 0;
    for (int i = 0; array[i] != NULL; i++)
        nb_elements++;
    return nb_elements;
}

bool is_element_present(void **array, void *element,
bool (*compare_function)(void *, void *))
{
    if (compare_function == NULL) {
        write(2, "Compare function is NULL: is_element_present\n", 45);
        return false;
    }
    if (array == NULL)
        return false;
    for (int i = 0; array[i] != NULL; i++)
        if (compare_function(array[i], element))
            return true;
    return false;
}

int get_element_index(void **array, void *element,
bool (*compare_function)(void *, void *))
{
    if (compare_function == NULL || array == NULL || element == NULL) {
        write(2, "Null parameter: get_element_index\n", 34);
        return -1;
    }
    for (int i = 0; array[i] != NULL; i++)
        if (compare_function(array[i], element))
            return i;
    return -1;
}

void *get_element(void **array, int index)
{
    if (index >= get_array_size(array) || index < 0) {
        write(2, "Index out of range: get_element\n", 32);
        return NULL;
    }
    return array[index];
}
