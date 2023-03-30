/*
** EPITECH PROJECT, 2022
** flag str
** File description:
** flag str
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int print_putstr(struct params_s *params, va_list ap)
{
    int ret = 0;
    char *str = va_arg(ap, char *);
    int len = my_strlen(str);

    if (params->pres != -1)
        len = params->pres;
    if (!params->val[4])
        ret += putxchar(params->width - len, ' ');
    ret += my_putstrcap(str, len);
    if (params->val[4])
        ret += putxchar(params->width - len, ' ');
    return ret;
}
