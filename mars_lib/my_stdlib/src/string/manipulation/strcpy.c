/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strcpy
*/

#include "my_stdlib.h"

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
