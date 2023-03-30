/*
** EPITECH PROJECT, 2022
** print.h
** File description:
** print.h
*/

#include "utils.h"

#ifndef _PRINT_H__
    #define _PRINT_H__

    int print_scientific_min(struct params_s *params, va_list ap);
    int print_scientific_maj(struct params_s *params, va_list ap);
    int print_float(struct params_s *params, va_list ap);
    int print_if_no_ascii(struct params_s *params, va_list ap);
    int print_putchar(struct params_s *params, va_list ap);
    int print_putstr(struct params_s *params, va_list ap);
    int print_put_nbr(struct params_s *params, va_list ap);
    int print_bin(struct params_s *params, va_list ap);
    int print_hexa_min(struct params_s *params, va_list ap);
    int print_hexa_maj(struct params_s *params, va_list ap);
    int print_octal(struct params_s *params, va_list ap);
    int print_decimal(struct params_s *params, va_list ap);
    int print_pointer(struct params_s *params, va_list ap);
    int print_magnitude_min(struct params_s *params, va_list ap);
    int print_magnitude_maj(struct params_s *params, va_list ap);

#endif
