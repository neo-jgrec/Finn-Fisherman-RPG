/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strdup
*/

#include "my_stdlib.h"

char *my_strdup(const char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (new_str == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}

char *my_strndup(const char *str, size_t n)
{
    size_t i = 0;
    char *new_str = malloc(sizeof(char) * (n + 1));

    if (new_str == NULL)
        return (NULL);
    for (; str[i] != '\0' && i < n; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}
