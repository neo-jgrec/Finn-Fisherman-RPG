/*
** EPITECH PROJECT, 2022
** ml_strupcase
** File description:
** ml_strupcase
*/

#include <stdbool.h>
#include <sys/types.h>

static bool ml_char_islow(const char c)
{
    if (c >= 'a' && c <= 'z')
        return (true);
    return (false);
}

void my_strupcase(char **str)
{
    for (size_t i = 0; (*str)[i] != '\0'; i++){
        if (ml_char_islow((*str)[i]))
            (*str)[i] -= 32;
    }
}
