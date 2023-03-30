/*
** EPITECH PROJECT, 2022
** flag scientific
** File description:
** flag scientific
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

struct width_s {
    int width;
    int width2;
};

int my_len_scientific(double nb, int prec)
{
    int count = 0;
    long long_part = (long)(nb);
    double decpart = (nb - (double)(long_part));

    decpart = (nb < 0) ? -decpart : decpart;
    count += my_len_nbr_long(long_part);
    if (prec > 0)
        count ++;
    count += prec;
    count += 1;
    return count;
}

static int param_scientific_min(struct params_s *params, double nb,
    struct width_s wi, int pres)
{
    int ret = 0;

    if (params->val[0])
        wi.width--;
    if (!params->val[4])
        ret += putxchar(wi.width, ' ');
    if (params->val[0] && !params->val[5])
        ret += my_putchar(' ');
    if (nb >= 0 && params->val[3])
        ret += my_putchar('+');
    if (nb < 0)
        ret += write(1, "-", 1);
    ret += putxchar(wi.width2, '0');
    ret += put_scientific_min(nb, pres);
    if (params->val[4])
        ret += putxchar(wi.width, ' ');
    return ret;
}

static int param_scientific_maj(struct params_s *params, double nb,
    struct width_s wi, int pres)
{
    int ret = 0;

    if (params->val[0])
        wi.width--;
    if (!params->val[4])
        ret += putxchar(wi.width, ' ');
    if (params->val[0] && !params->val[5])
        ret += my_putchar(' ');
    if (nb >= 0 && params->val[3])
        ret += my_putchar('+');
    if (nb < 0)
        ret += write(1, "-", 1);
    ret += putxchar(wi.width2, '0');
    ret += put_scientific_maj(nb, pres);
    if (params->val[4])
        ret += putxchar(wi.width, ' ');
    return ret;
}

int print_scientific_min(struct params_s *params, va_list ap)
{
    int ret = 0;
    double nb = va_arg(ap, double);
    int len = 0;
    struct width_s wi = {0, 0};
    int pres = params->pres;

    if (pres == -1)
        pres = 6;
    len = my_len_scientific(nb, pres);
    wi.width = params->width - len;
    if (params->val[5]) {
        wi.width2 = wi.width;
        wi.width = 0;
    }
    ret += param_scientific_min(params, nb, wi, pres);
    return ret;
}

int print_scientific_maj(struct params_s *params, va_list ap)
{
    int ret = 0;
    double nb = va_arg(ap, double);
    int len = 0;
    struct width_s wi = {0, 0};
    int pres = params->pres;

    if (pres == -1)
        pres = 6;
    len = my_len_scientific(nb, pres);
    wi.width = params->width - len;
    if (params->val[5]) {
        wi.width2 = wi.width;
        wi.width = 0;
    }
    ret += param_scientific_maj(params, nb, wi, pres);
    return ret;
}
