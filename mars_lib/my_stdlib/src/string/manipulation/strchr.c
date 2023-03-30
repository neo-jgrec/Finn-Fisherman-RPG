/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strchr
*/

#include "my_stdlib.h"

char *my_strchr(const char *str, int c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return ((char *) &str[i]);
    return (NULL);
}
