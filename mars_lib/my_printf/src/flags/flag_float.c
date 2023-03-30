/*
** EPITECH PROJECT, 2022
** flag float
** File description:
** flag float
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int my_len_nbr_long(long nb)
{
    int count = 1;
    if (nb == 0)
        return count;
    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    for (; (nb / 10) != 0; nb /= 10, count++);
    return (count);
}

int my_len_float(double nb, int prec)
{
    int count = 0;
    long long_part = (long)(nb);
    double decpart = (nb - (double)(long_part));

    decpart = (nb < 0) ? -decpart : decpart;
    count += my_len_nbr_long(long_part);
    if (prec > 0)
        count ++;
    count += prec;
    return count;
}

static int param_float(struct params_s *params, double nb, int width, int pres)
{
    int ret = 0;
    int width2 = 0;

    if (params->val[5]) {
        width2 = width;
        width = 0;
    }
    if (params->val[0])
        width--;
    if (!params->val[4])
        ret += putxchar(width, ' ');
    if (params->val[0] && !params->val[5])
        ret += my_putchar(' ');
    if (nb >= 0 && params->val[3])
        ret += my_putchar('+');
    ret += my_put_floatpres(nb, pres, width2);
    if (params->val[4])
        ret += putxchar(width, ' ');
    return ret;
}

int print_float(struct params_s *params, va_list ap)
{
    int ret = 0;
    double nb = va_arg(ap, double);
    int len = 0;
    int width = 0;
    int pres = params->pres;

    if (pres == -1)
        pres = 6;
    len = my_len_float(nb, pres);
    width = params->width - len;
    ret += param_float(params, nb, width, pres);
    return ret;
}
