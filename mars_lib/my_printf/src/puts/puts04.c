/*
** EPITECH PROJECT, 2022
** put scientific
** File description:
** return scientific notation
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

int my_declen(long val);

double my_round(double val, long int precision)
{
    long int len = my_declen((int)val) + precision - 1;
    double power = my_pow(10, len);

    val *= power;
    if (val >= 0)
        return (long long)(val + 0.5) / power;
    else
        return (long long)(val - 0.5) / power;
}

static int my_put_float_custom(long double number, int prec)
{
    long long_part = (long long)(number);
    double decpart = (number - (long double)(long_part));
    int count = 0;
    double tmp_decpart;

    count += my_put_nbr(long_part);
    if (prec > 0) {
        count += write(1, ".", 1);
        for (int i = 0; i < prec; i++) {
            decpart *= 10;
            tmp_decpart = decpart;
            decpart -= (long long)(decpart);
            decpart = my_round(decpart, prec);
            count += my_put_nbr((long int)(tmp_decpart));
        }
    }
    return count;
}

static int my_execption_zero(int prec)
{
    int count = 0;

    count += my_put_nbr(0);
    if (prec != 0)
        count += write(1, ".", 1);
    for (int i = 0; i < prec; i++)
        count += my_put_nbr(0);
    write(1, "e+00", 4);
    return count;
}

int put_scientific_min(double number, int prec)
{
    int count = 0;
    int exp = 0;

    if (number == 0.0)
        return my_execption_zero(prec);
    number = (number < 0) ? -number : number;
    for (; number >= 10; exp++, number /= 10);
    for (; number < 1; exp--, number *= 10);
    count += my_put_float_custom(number, prec);
    count += write(1, "e", 1);
    if (exp < 0) {
        count += write(1, "-", 1);
        exp *= -1;
    } else
        count += write(1, "+", 1);
    if (exp < 10)
        count += write(1, "0", 1);
    count += my_put_nbr(exp);
    return count;
}

int put_scientific_maj(double number, int prec)
{
    int count = 0;
    int exp = 0;

    if (number == 0.0)
        return my_execption_zero(prec);
    number = (number < 0) ? -number : number;
    for (; number >= 10; exp++, number /= 10);
    for (; number < 1; exp--, number *= 10);
    count += my_put_float_custom(number, prec);
    count += write(1, "E", 1);
    if (exp < 0) {
        count += write(1, "-", 1);
        exp *= -1;
    } else
        count += write(1, "+", 1);
    if (exp < 10)
        count += write(1, "0", 1);
    count += my_put_nbr(exp);
    return count;
}
