/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strstr_index
*/

#include "my_stdlib.h"

int my_strstr_index(const char *fullstring, const char *substring)
{
    for (int i = 0, j = 0; fullstring[i] != '\0'; i++) {
        if (fullstring[i] == substring[j])
            j++;
        else
            j = 0;
        if (substring[j] == '\0')
            return (i - j + 1);
    }
    return (-1);
}
