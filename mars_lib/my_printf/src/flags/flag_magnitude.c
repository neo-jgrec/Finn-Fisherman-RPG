/*
** EPITECH PROJECT, 2022
** flag magnitude
** File description:
** flag magnitude
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int print_magnitude_min(UNUSED struct params_s *params, va_list ap)
{
    int ret = 0;
    double nb = va_arg(ap, double);

    ret += my_magnitude_min(nb, 6);
    return ret;
}

int print_magnitude_maj(UNUSED struct params_s *params, va_list ap)
{
    int ret = 0;
    double nb = va_arg(ap, double);

    ret += my_magnitude_maj(nb, 6);
    return ret;
}
