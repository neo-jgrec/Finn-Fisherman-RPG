/*
** EPITECH PROJECT, 2022
** flag bin
** File description:
** flag bin
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int my_len_base(long long nb, int base)
{
    int count = 1;
    if (nb == 0)
        return count;
    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    for (; (nb / base) != 0; nb /= base, count++);
    return (count);
}

int print_bin(struct params_s *params, va_list ap)
{
    int nb = va_arg(ap, int);
    int ret = 0;
    char pad = ' ';
    int precision = minnbr(params->pres, 0) - my_len_base(nb, 2);
    int padding = params->width - my_len_base(nb, 2) - minnbr(precision, 0);

    if (params->val[5] && params->pres <= 0)
        pad = '0';
    if (!params->val[4])
        ret += putxchar(padding, pad);
    ret += putxchar(params->pres - my_len_base(nb, 2),'0');
    ret += binflag(nb, "01");
    if (params->val[4])
        ret += putxchar(padding, ' ');
    return ret;
}

int print_if_no_ascii(UNUSED struct params_s *params, va_list ap)
{
    return put_if_no_ascii(va_arg(ap, char *));
}
