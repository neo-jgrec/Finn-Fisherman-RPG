/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** free_stw
*/

#include "rpg.h"

void a_freestw(char **stw)
{
    for (int i = 0; stw[i] != NULL; i++)
        free(stw[i]);
    free(stw);
}
