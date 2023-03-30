/*
** EPITECH PROJECT, 2022
** puts3
** File description:
** puts3
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

int my_declen(long val)
{
    int len;
    for (len = 0; val > 0; len++)
        val /= 10;
    return len;
}

int my_put_float(double number, int prec)
{
    int count = 0;
    long long_part = (long)(number);
    double decpart = (number - (double)(long_part));
    double tmp_decpart;

    decpart = (number < 0) ? -decpart : decpart;
    count += my_put_nbr(long_part);
    if (prec > 0)
        count += write(1, ".", 1);
    tmp_decpart = decpart;
    for (int i = 0; i != prec; i++) {
        tmp_decpart *= 10;
        decpart = my_round(decpart, prec);
        count += my_put_nbr((int)(tmp_decpart));
        tmp_decpart -= (int)(tmp_decpart);
    }
    return count;
}

int my_put_floatpres(double number, int prec, int width2)
{
    int count = 0;
    long long_part = (long)(number);
    double decpart = (number - (double)(long_part));
    double tmp_decpart;

    decpart = (number < 0) ? -decpart : decpart;
    count += my_put_nbrpres(long_part, width2);
    if (prec > 0)
        count += write(1, ".", 1);
    tmp_decpart = decpart;
    for (int i = 0; i != prec; i++) {
        tmp_decpart *= 10;
        decpart = my_round(decpart, prec);
        count += my_put_nbr((int)(tmp_decpart));
        tmp_decpart -= (int)(tmp_decpart);
    }
    return count;
}
