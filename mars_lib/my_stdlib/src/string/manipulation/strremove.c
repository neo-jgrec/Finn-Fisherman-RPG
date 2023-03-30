/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strremove
*/

#include "my_stdlib.h"

char *my_strremove(char *str, const char *str_to_remove)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;

    for (; str[i] != '\0'; i++) {
        if (my_strchr(str_to_remove, str[i]) == NULL) {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return (new_str);
}
