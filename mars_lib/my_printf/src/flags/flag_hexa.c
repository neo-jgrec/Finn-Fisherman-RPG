/*
** EPITECH PROJECT, 2022
** flag hexa
** File description:
** flag hexa
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int print_hexa_min(struct params_s *params, va_list ap)
{
    int nb = va_arg(ap, int);
    int ret = 0;
    char pad = ' ';
    int precision = minnbr(params->pres, 0) - my_len_base(nb, 16);
    int padding = params->width - my_len_base(nb, 16) - minnbr(precision, 0);

    if (params->val[1]) {
        padding -= 2;
        ret += my_putstr("0x");
    }
    if (params->val[5] && params->pres <= 0)
        pad = '0';
    if (!params->val[4])
        ret += putxchar(padding, pad);
    ret += putxchar(params->pres - my_len_base(nb, 16),'0');
    ret += binflag(nb, "0123456789abcdef");
    if (params->val[4])
        ret += putxchar(padding, ' ');
    return ret;
}

int print_hexa_maj(struct params_s *params, va_list ap)
{
    int nb = va_arg(ap, int);
    int ret = 0;
    char pad = ' ';
    int precision = minnbr(params->pres, 0) - my_len_base(nb, 16);
    int padding = params->width - my_len_base(nb, 16) - minnbr(precision, 0);

    if (params->val[1]) {
        padding -= 2;
        ret += my_putstr("0x");
    }
    if (params->val[5] && params->pres <= 0)
        pad = '0';
    if (!params->val[4])
        ret += putxchar(padding, pad);
    ret += putxchar(params->pres - my_len_base(nb, 16),'0');
    ret += binflag(nb, "0123456789ABCDEF");
    if (params->val[4])
        ret += putxchar(padding, ' ');
    return ret;
}
