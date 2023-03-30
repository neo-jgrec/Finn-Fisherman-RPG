/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** itoa
*/

#include "my_stdlib.h"

char *my_itoa(int nb)
{
    int i = 0;
    int sign = 1;
    char *str = malloc(sizeof(char) * 12);

    if (nb < 0) {
        sign = -1;
        nb *= -1;
    }
    for (; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    if (sign == -1) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}
