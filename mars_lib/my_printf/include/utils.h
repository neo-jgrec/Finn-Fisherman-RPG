/*
** EPITECH PROJECT, 2022
** header for my lib
** File description:
** lib
*/

#ifndef _MY_H__
    #define _MY_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>

    #define UNUSED __attribute__((unused))

    struct params_s {
        char *param;
        int val[6];
        int width;
        int pres;
        int lfield;
    };

    struct put_s {
        char *c;
        int (*dir)(struct params_s *, va_list);
    };
    typedef union {
        float f;
        struct {
            unsigned int man : 23;
            unsigned int expo : 8;
            unsigned int s : 1;
        } st;
        } float_cast;

    int simpleparam(char *str, struct params_s *params, int *passed);
    int minnbr(int nb, int min);
    int maxnbr(int nb, int max);
    int putxchar(int nb, char c);
    int my_pow(int a, int b);
    int put_scientific_maj(double number, int prec);
    int put_scientific_min(double number, int prec);
    int my_put_float(double number, int prec);
    int put_if_no_ascii(char *);
    int put_pointer(void *ptr, int pres);
    int my_putchar(char c);
    int my_putstrcap(char *str, int pres);
    int my_putstr(char *str);
    int my_put_nbr(long long nb);
    int binflag(unsigned int nb, char *base);
    int my_putstr(char *str);
    int get_width(char *str, int *passed);
    int get_pres(char *str, int *passed);
    int get_length(char const *str, int *passed);
    int my_strlen(char const *str);
    char *my_strdup(char const *src);
    int my_len_base(long long nb, int base);
    int float_params(struct params_s prams, double nb);
    double my_round(double val, long int precision);
    int my_put_nbrpres(long long nb, int pres);
    int my_put_floatpres(double number, int prec, int width2);
    int my_magnitude_min(double number, int prec);
    int my_magnitude_maj(double number, int prec);
    int my_len_float(double nb, int prec);
    int my_len_scientific(double nb, int prec);
    int my_len_lld(long long nb);
    int my_len_nbr_long(long nb);

#endif
