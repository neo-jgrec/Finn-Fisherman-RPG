/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strcat_inf
*/

#include <stdarg.h>
#include "my_stdlib.h"

static char *my_strcat_realloc(char *str, char *to_add)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + my_strlen(to_add) + 1));

    tmp = my_strcpy(tmp, str);
    tmp = my_strcat(tmp, to_add);
    free(str);
    return (tmp);
}

char *my_strcat_inf(int nb, ...)
{
    va_list ap;
    char *str = malloc(sizeof(char) * 1);
    char *to_add = NULL;

    str[0] = '\0';
    va_start(ap, nb);
    for (int i = 0; i < nb; i++) {
        to_add = va_arg(ap, char *);
        str = my_strcat_realloc(str, to_add);
    }
    va_end(ap);
    return (str);
}
