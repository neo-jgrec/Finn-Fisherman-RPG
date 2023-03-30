/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strstr
*/

#include "my_stdlib.h"

char *my_strstr(const char *fullstring, const char *substring)
{
    for (int i = 0, j = 0; fullstring[i] != '\0'; i++) {
        if (fullstring[i] == substring[j])
            j++;
        else
            j = 0;
        if (substring[j] == '\0')
            return ((char *)fullstring + i - j + 1);
    }
    return (NULL);
}
