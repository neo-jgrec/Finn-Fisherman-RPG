/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_rpg
*/

#include "rpg.h"

rpg_t *init_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (rpg == NULL)
        return NULL;
    return rpg;
}