/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** cleanstr
*/

#include "my_stdlib.h"

char *clean_str(char *str, const char *to_clean)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;

    if (new_str == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++) {
        if (my_strchr(to_clean, str[i]) == NULL) {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return (new_str);
}
