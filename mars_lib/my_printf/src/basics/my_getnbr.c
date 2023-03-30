/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get nbr inside many thing
*/

#include <unistd.h>
#include <limits.h>

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    int x = a;
    for (int i = 0; i < b - 1; i++)
        x *= a;
    return x;
}

static int find_start(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 49 && str[i] <= 57) {
            return i;
        }
    }
    return -1;
}

static int find_len(char const *str, int start)
{
    int a = 0;
    for (int i = start; str[i] >= 48 && str[i] <= 57; i++) {
        a++;
    }
    return a;
}

static int calcul_nbr(char const *str, int start, int len)
{
    long nbr = 0;

    for (int i = 0; i < len; i++) {
        nbr += (long)(str[start + i] - 48) * (long)(my_pow(10, len - 1 - i));
        if (nbr > INT_MAX)
            return 0;
    }
    if (nbr < 0) {
        return 0;
    }
    return nbr;
}

int my_getnbr(char const *str)
{
    int start = find_start(str);
    int len = 0;
    int nbr = 0;

    if (start == -1) {
        return 0;
    }
    len = find_len(str, start);
    if (len > 10) {
        return 0;
    }
    nbr = calcul_nbr(str, start, len);
    return nbr;
}
