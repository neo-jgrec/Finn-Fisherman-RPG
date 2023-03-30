/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "utils.h"

int my_put_nbr(long long nb)
{
    int ret = 0;
    long long i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        ret++;
    }
    for (; (nb / i) >= 10; i *= 10);
    for (; i > 0; i /= 10, ret++)
        my_putchar((nb / i) % 10 + '0');
    return ret;
}
