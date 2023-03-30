/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** get nbr inside many thing
*/

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "utils.h"

int my_getnbr(char const *str);

static int param1(char c, struct params_s *params)
{
    for (int i = 0; i < 6; i++) {
        if (c == params->param[i]) {
            params->val[i] = 1;
            return 1;
        }
    }
    return 0;
}

int simpleparam(char *str, struct params_s *params, int *passed)
{
    for (int i = 0; param1(str[i], params); i++)
        *passed += 1;
    return 0;
}

int get_pres(char *str, int *passed)
{
    int ret = 0;
    char *str2;
    int l = 0;
    if (str[0] != '.')
        return -1;
    *passed += 1;
    for (; str[l + 1] > 47 && str[l + 1] < 58; l ++) {
        *passed += 1;
    }

    str2 = malloc(sizeof(char) * (l + 1));
    for (int i = 0; str[i + 1] > 47 && str[i + 1] < 58; i++)
        str2[i] = str[i + 1];
    str2[l] = '\0';
    ret = my_getnbr(str2);
    free(str2);
    return ret;
}

int get_width(char *str, int *passed)
{
    int ret = 0;
    char *str2;
    int l = 0;

    for (; str[l] > 47 && str[l] < 58; l ++) {
        *passed += 1;
    }
    str2 = malloc(sizeof(char) * (l + 1));
    for (int i = 0; str[i] > 47 && str[i] < 58; i++)
        str2[i] = str[i];
    str2[l] = '\0';
    ret = my_getnbr(str2);
    free(str2);
    return ret;
}
