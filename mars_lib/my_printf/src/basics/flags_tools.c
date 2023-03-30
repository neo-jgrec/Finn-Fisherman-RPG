/*
** EPITECH PROJECT, 2022
** printxchar
** File description:
** printxchar
*/

#include <unistd.h>
#include "utils.h"

int putxchar(int nb, char c)
{
    int ret = 0;

    for (int i = 0; i < nb; i++) {
        my_putchar(c);
        ret++;
    }
    return ret;
}

int maxnbr(int nb, int max)
{
    if (nb > max)
        return max;
    return nb;
}

int minnbr(int nb, int min)
{
    if (nb < min)
        return min;
    return nb;
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return my_strlen(str);
}
