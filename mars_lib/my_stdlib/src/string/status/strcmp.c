/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** my_strcmp
*/

#include "my_stdlib.h"
#include <stddef.h>

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    if (s1 == NULL || s2 == NULL)
        return (s1 == NULL && s2 == NULL) ? 0 : (s1 == NULL ? -1 : 1);
    for (; i < n; i++) {
        if (s1[i] == '\0' || s1[i] != s2[i])
            break;
    }
    if (i == n)
        return 0;
    return (unsigned char) s1[i] - (unsigned char) s2[i];
}
