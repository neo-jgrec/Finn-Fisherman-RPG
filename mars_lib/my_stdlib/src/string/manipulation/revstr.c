/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** revstr
*/

#include "my_stdlib.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char tmp;

    for (; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    return (str);
}
