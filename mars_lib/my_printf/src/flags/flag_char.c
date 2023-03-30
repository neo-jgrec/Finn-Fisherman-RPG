/*
** EPITECH PROJECT, 2022
** print tfncts
** File description:
** print tfncts
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int print_putchar(struct params_s *params, va_list ap)
{
    int ret = 0;
    if (!params->val[4])
        ret += putxchar(params->width - 1, ' ');
    ret += my_putchar(va_arg(ap, int));
    if (params->val[4])
        ret += putxchar(params->width - 1, ' ');
    return ret;
}
