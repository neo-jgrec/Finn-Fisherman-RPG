/*
** EPITECH PROJECT, 2022
** flag octal
** File description:
** flag octal
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int print_octal(struct params_s *params, va_list ap)
{
    int nb = va_arg(ap, int);
    int ret = 0;
    char pad = ' ';
    int precision = minnbr(params->pres, 0) - my_len_base(nb, 8);
    int padding = params->width - my_len_base(nb, 8) - minnbr(precision, 0);

    if (params->val[1]) {
        padding--;
        ret += my_putchar('0');
    }
    if (params->val[5] && params->pres <= 0)
        pad = '0';
    if (!params->val[4])
        ret += putxchar(padding, pad);
    ret += putxchar(params->pres - my_len_base(nb, 8),'0');
    ret += binflag(nb, "01234567");
    if (params->val[4])
        ret += putxchar(padding, ' ');
    return ret;
}
