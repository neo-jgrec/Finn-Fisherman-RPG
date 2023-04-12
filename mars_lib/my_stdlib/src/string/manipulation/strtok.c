/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** my_strtok
*/

#include "malloc.h"
#include "my_stdlib.h"

char *my_strtok(char *str, const char *delim)
{
    static char *saveptr = NULL;
    char *token = NULL;

    if (str != NULL)
        saveptr = str;
    if (saveptr == NULL || *saveptr == '\0')
        return NULL;
    token = saveptr;
    while (*saveptr != '\0') {
        if (my_strchr(delim, *saveptr) != NULL) {
            *saveptr++ = '\0';
            return token;
        }
        saveptr++;
    }
    saveptr = NULL;
    return token;
}
