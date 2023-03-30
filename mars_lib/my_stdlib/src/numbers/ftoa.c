/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** ftoi
*/

#include "my_stdlib.h"

char *my_ftoa(float nb, int precision)
{
    char *str = malloc(sizeof(char) * (precision + 2));
    int i = 0;
    int nb_int = (int)nb;
    float nb_float = nb - nb_int;

    for (; nb_int > 0; i++) {
        str[i] = (nb_int % 10) + '0';
        nb_int /= 10;
    }
    my_revstr(str);
    str[i] = '.';
    i++;
    for (; i < precision + 2; i++) {
        nb_float *= 10;
        str[i] = (int)nb_float + '0';
        nb_float -= (int)nb_float;
    }
    str[i] = '\0';
    return (str);
}
