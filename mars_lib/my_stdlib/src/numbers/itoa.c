/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** itoa
*/

#include "my_stdlib.h"

static char *return_zero(char *str)
{
    str[0] = '0';
    str[1] = '\0';
    return str;
}

char *my_itoa(int nb)
{
    int i = 0;
    int sign = 1;
    char *str = malloc(sizeof(char) * 12);

    if (nb == 0)
        return return_zero(str);
    if (nb < 0) {
        sign = -1;
        nb *= -1;
    }
    for (; nb > 0; str[i] = nb % 10 + '0', nb /= 10, i++);
    if (sign == -1) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}
