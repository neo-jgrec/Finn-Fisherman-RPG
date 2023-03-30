/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** strsplit
*/

#include "my_stdlib.h"

char **my_strsplit(const char *str, const char delim)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **new_str = malloc(sizeof(char *) * (my_strlen(str) + 1));

    if (new_str == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            new_str[j][k] = '\0';
            j++;
            k = 0;
        } else {
            new_str[j][k] = str[i];
            k++;
        }
    }
    new_str[j][k] = '\0';
    new_str[j + 1] = NULL;
    return (new_str);
}
