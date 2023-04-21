/*
** EPITECH PROJECT, 2023
** mlgt_convert_int_to_str
** File description:
** mlgt_convert_int_to_str
*/

#include "rpg.h"

char *my_nbr_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (my_nbrlen(nb) + 1));
    char temp;
    size_t parse = 0;

    if (!str)
        return (NULL);
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    for (; nb != 0; parse++) {
        temp = (nb % 10) + 48;
        str[parse] = temp;
        nb /= 10;
    }
    str[parse] = '\0';
    str = my_revstr(str);
    return (str);
}
