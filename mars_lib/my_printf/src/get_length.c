/*
** EPITECH PROJECT, 2022
** my_get_lengthfields
** File description:
** my_getlengthfield
*/

#include "utils.h"

static int my_comp(char const *to_find, char *str)
{
    for (int i = 0; to_find[i] != '\0'; i++) {
        if (to_find[i] != str[i])
            return 0;
    }
    return 1;
}

static int my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_comp(to_find, &str[i]))
            return 1;
    }
    return 0;
}

static int islength(char c)
{
    char str[7] = "hlLzjt";
    for (int i = 0; i < 7; i++) {
        if (c == str[i])
            return 1;
    }
    return 0;
}

int get_length(char const *str, int *passed)
{
    if (!islength(str[0]))
        return 0;
    char *lengthfield[8] = {"ll", "l", "hh",
        "h", "L", "z", "j", "t"};
    for (int i = 0; i < 8; i ++) {
        if (my_strstr(my_strdup(str), lengthfield[i])) {
            *passed += my_strlen(lengthfield[i]);
            return i + 1;
        }
    }
    return 0;
}
