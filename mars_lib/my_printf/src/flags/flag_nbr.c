/*
** EPITECH PROJECT, 2022
** flag nbr
** File description:
** flag nbr
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int my_len_lld(long long nb)
{
    int count = 1;
    if (nb == 0)
        return count;
    if (nb < 0) {
        nb = nb * -1;
    }
    for (; (nb / 10) != 0; nb /= 10, count++);
    return (count);
}

static int param_nbr(struct params_s *params, long long nb, int width, int pres)
{
    int ret = 0;
    if (params->val[5] && params->pres == -1) {
        pres = width;
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
    ret += my_put_nbrpres(nb, pres);
    if (params->val[4])
        ret += putxchar(width, ' ');
    return ret;
}

int print_put_nbr(struct params_s *params, va_list ap)
{
    int ret = 0;
    long long int nb = 0;
    int len = 0;
    int width = 0;
    int pres = 0;

    if (params->lfield == 1)
        nb = va_arg(ap, long long int);
    else if (params->lfield == 2)
        nb = va_arg(ap, long int);
    else
        nb = va_arg(ap, int);
    len = my_len_lld(nb);
    pres = minnbr(params->pres - len, 0);
    width = params->width - pres - len;
    if (nb < 0)
        width -= 1;
    ret += param_nbr(params, nb, width, pres);
    return ret;
}
