/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    int size = 0;

    for (int i = 0; src[i] != '\0'; i++)
        size++;
    char *duped = malloc(sizeof(char) * size + 1);
    my_strcpy(duped, src);
    return duped;
}
