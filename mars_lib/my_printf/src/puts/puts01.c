/*
** EPITECH PROJECT, 2022
** put_fncts
** File description:
** put_fncts
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_putstrcap(char *str, int pres)
{
    write(1, str, maxnbr(pres, my_strlen(str)));
    return maxnbr(pres, my_strlen(str));
}

int my_put_nbrpres(long long nb, int pres)
{
    int ret = 0;
    long long i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        ret++;
    }
    ret += putxchar(pres, '0');
    for (; (nb / i) >= 10; i *= 10);
    for (; i > 0; i /= 10, ret++)
        my_putchar((nb / i) % 10 + '0');
    return ret;
}

int binflag(unsigned int nb, char *base)
{
    int i = nb;
    int nb_digit = 0;
    char *nbf;
    int base_size = my_strlen(base);

    for (; i != 0; nb_digit++)
        i /= base_size;
    i = nb;
    nbf = malloc(sizeof(char) * (nb_digit + 1));
    for (int j = 0; i != 0; j++) {
        nbf[nb_digit - j - 1] = base[i % base_size];
        i /= base_size;
    }
    my_putstr(nbf);
    return nb_digit;
}
