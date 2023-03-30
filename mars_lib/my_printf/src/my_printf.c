/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** mini_printf
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "utils.h"
#include "print.h"

static const struct put_s puts_fncts[] = {
    {"c", print_putchar},
    {"d", print_put_nbr},
    {"i", print_put_nbr},
    {"s", print_putstr},
    {"b", print_bin},
    {"x", print_hexa_min},
    {"X", print_hexa_maj},
    {"o", print_octal},
    {"u", print_decimal},
    {"p", print_pointer},
    {"S", print_if_no_ascii},
    {"f", print_float},
    {"F", print_float},
    {"e", print_scientific_min},
    {"E", print_scientific_maj},
    {"g", print_magnitude_min},
    {"G", print_magnitude_maj}
};

int print_error(struct params_s *params, char flag)
{
    int ret = 0;
    ret += my_putchar('%');
    for (int i = 1; i < 6; i++)
        if (params->val[i])
            ret += my_putchar(params->param[i]);
    if (params->width != 0)
        ret += my_put_nbr(params->width);
    if (params->pres != -1){
        ret += my_putchar('.');
        ret += my_put_nbr(params->pres);
    }
    ret += my_putchar(flag);
    return ret;
}

void sort_param(struct params_s *params)
{
    if (params->val[0] && params->val[3])
        params->val[0] = 0;
    if (params->val[4] && params->val[5])
        params->val[5] = 0;
}

static int findflag(struct params_s *params, va_list args, char flag, int *ret)
{
    for (int i = 0; i < 17; i++) {
        if (flag == puts_fncts[i].c[0] ||
            flag == puts_fncts[i].c[0]) {
            return puts_fncts[i].dir(params, args);
        }
    }
    if (flag == 'n'){
        *va_arg(args, int *) = *ret;
        return 0;
    }
    if (flag == '%')
        return write(1, "%", 1);
    return print_error(params, flag);
}

static int getparamflag(char *format, int i, va_list args, int *ret)
{
    struct params_s params = {my_strdup(" #'+-0"),
        {0,0,0,0,0,0}, 0, -1, 0};

    simpleparam(format + i, &params, &i);
    params.width = get_width(format + i, &i);
    params.pres = get_pres(format + i, &i);
    params.lfield = get_length(format + i, &i);
    sort_param(&params);
    *ret += findflag(&params, args, format[i], ret);
    free(format);
    free(params.param);
    return i;
}

int my_printf(const char *format, ...)
{
    int ret = 0;
    int i = 0;
    va_list args;
    int isflag = 0;


    va_start(args, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == '\0')
            return -1;
        if (format[i] != '%')
            ret += my_putchar(format[i]);
        else
            i = getparamflag(my_strdup(format), i + 1, args, &ret);
    }
    va_end(args);
    return (((ret == 0 && format[0] == '%' ) || isflag == 1) ? -1 : ret);
}
