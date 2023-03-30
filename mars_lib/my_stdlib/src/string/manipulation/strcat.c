/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strcat
*/

#include <stddef.h>

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0'; j++, i++)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}

char *my_strcat_char(char *dest, const char src)
{
    int i = 0;

    for (; dest[i] != '\0'; i++);
    dest[i] = src;
    dest[i + 1] = '\0';
    return (dest);
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    size_t j = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0' && j < n; j++, i++)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}
