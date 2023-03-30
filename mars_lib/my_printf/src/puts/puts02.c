/*
** EPITECH PROJECT, 2022
** puts2
** File description:
** puts2
*/

#include <unistd.h>
#include <stdarg.h>
#include "utils.h"

static int size_t_binflag(size_t nb, char *base)
{
    size_t i = nb;
    size_t nb_digit = 0;
    char *nbf;
    size_t base_size = my_strlen(base);

    for (; i != 0; nb_digit++)
        i /= base_size;
    i = nb;
    nbf = malloc(sizeof(char) * (nb_digit + 1));
    for (int j = 0; i != 0; j++) {
        nbf[nb_digit - j - 1] = base[i % base_size];
        i /= base_size;
    }
    my_putstr(nbf);
    return nb_digit;
}

int put_pointer(void *ptr, int pres)
{
    int ret = 0;
    if (ptr == NULL)
        return my_putstr("(nil)");
    ret += my_putstr("0x");
    ret += putxchar(pres, '0');
    ret += size_t_binflag((size_t)ptr, "0123456789abcdef");
    return ret;
}

static void soctflag(unsigned int nb, char *base)
{
    int i = nb;
    int nb_digit = 1;
    char *nbf;
    int base_size = my_strlen(base);

    for (; (i / 8) != 0; nb_digit++)
        i /= base_size;
    i = nb;
    nbf = malloc(sizeof(char) * (nb_digit + 1));
    for (int j = 0; i != 0; j++) {
        nbf[nb_digit - j - 1] = base[i % base_size];
        i /= base_size;
    }
    if (nb_digit == 1)
        my_putstr("00");
    if (nb_digit == 2)
        my_putstr("0");
    my_putstr(nbf);
    free(nbf);
}

int put_if_no_ascii(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && str[i] < 127)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            soctflag((int)str[i], "01234567");
            count += 4;
        }
    }
    return count;
}
