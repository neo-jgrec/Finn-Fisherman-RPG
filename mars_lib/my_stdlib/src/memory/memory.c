/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** malloc
*/

#include "memory.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    for (size_t i = 0; i < n; i++)
        d[i] = s[i];
    return (dest);
}

void *my_memset(void *s, int c, size_t n)
{
    char *str = s;

    for (size_t i = 0; i < n; i++)
        str[i] = c;
    return (s);
}

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    if (d < s) {
        for (size_t i = 0; i < n; i++)
            d[i] = s[i];
    } else {
        for (size_t i = n; i > 0; i--)
            d[i - 1] = s[i - 1];
    }
    return (dest);
}
