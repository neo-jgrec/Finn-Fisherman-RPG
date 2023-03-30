/*
** EPITECH PROJECT, 2022
** flag nbr
** File description:
** flag nbr
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"
#include "my_printf.h"
#include "print.h"

static int my_put_float_custom(long double number, int prec)
{
    long long_part = (long long)(number);
    double decpart = (number - (long double)(long_part));
    int count = 0;
    double tmp_decpart;

    count += my_put_nbr(long_part);
    if (prec > 0)
        count += write(1, ".", 1);
    for (int i = 0; i < prec; i++) {
        decpart *= 10;
        tmp_decpart = decpart;
        decpart -= (long long)(decpart);
        decpart = my_round(decpart, prec);
        if ((long int)(tmp_decpart) == 0)
            break;
        count += my_put_nbr((long int)(tmp_decpart));
    }
    return count;
}

int my_magnitude_min(double number, int prec)
{
    if (my_len_float(number, prec) < my_len_scientific(number, prec))
        return my_put_float_custom(number, prec);
    else
        return put_scientific_min(number, prec);
}

int my_magnitude_maj(double number, int prec)
{
    if (my_len_float(number, prec) < my_len_scientific(number, prec))
        return my_put_float_custom(number, prec);
    else
        return put_scientific_maj(number, prec);
}
