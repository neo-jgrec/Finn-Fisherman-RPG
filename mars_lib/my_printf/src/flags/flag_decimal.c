/*
** EPITECH PROJECT, 2022
** flag decimal
** File description:
** flag decimal
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int print_decimal(struct params_s *params, va_list ap)
{
    int nb = va_arg(ap, int);
    int ret = 0;
    char pad = ' ';
    int precision = minnbr(params->pres, 0) - my_len_base(nb, 10);
    int padding = params->width - my_len_base(nb, 10) - minnbr(precision, 0);

    if (params->val[5] && params->pres <= 0)
        pad = '0';
    if (!params->val[4])
        ret += putxchar(padding, pad);
    ret += putxchar(params->pres - my_len_base(nb, 10),'0');
    ret += binflag(nb, "0123456789");
    if (params->val[4])
        ret += putxchar(padding, ' ');
    return ret;
}
