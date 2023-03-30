/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** alloc
*/

#include "memory.h"

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);

    if (new_ptr == NULL)
        return (NULL);
    if (ptr != NULL) {
        my_memcpy(new_ptr, ptr, size);
        free(ptr);
    }
    return (new_ptr);
}

void *my_calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    if (ptr == NULL)
        return (NULL);
    my_memset(ptr, 0, nmemb * size);
    return (ptr);
}
