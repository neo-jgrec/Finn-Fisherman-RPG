/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}
