/*
** EPITECH PROJECT, 2022
** flag pointer
** File description:
** flag pointer
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

static char plus_or_space(struct params_s *params, int *padding, int *ret)
{
    char plus = '\0';

    if (params->val[0])
        plus = ' ';
    if (params->val[3])
        plus = '+';
    if (plus > 0)
        *padding -= 1;
    if (plus == ' ')
        *ret += my_putchar(' ');
    return plus;
}

int print_pointer(struct params_s *params, va_list ap)
{
    int ret = 0;
    void *ptr = va_arg(ap, void *);
    int pre = params->pres - my_len_base((size_t)ptr, 16);
    int padding = params->width - my_len_base((size_t)ptr,
        16) - 2 - minnbr(pre, 0);
    char plus = plus_or_space(params, &padding, &ret);

    if (!params->val[4] && params->val[5] &&
            params->pres <= 0) {
        pre = padding;
        padding = 0;
    }
    if (!params->val[4])
        ret += putxchar(padding, ' ');
    if (plus == '+')
        ret += my_putchar(plus);
    ret += put_pointer(ptr, pre);
    if (params->val[4])
        ret += putxchar(padding, ' ');
    return ret;
}
