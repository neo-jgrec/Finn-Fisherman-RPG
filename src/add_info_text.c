/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** add_info_text
*/

#include "rpg.h"

void add_info_text(rpg_t *rpg, sfColor color,
    VEC pos, char *str)
{
    info_t **infos = rpg->infos;
    info_t *info = malloc(sizeof(info_t));

    if (info == NULL)
        return;
    info->cd = 3;
    info->color = color;
    info->pos = pos;
    info->str = str;
    info->next = *infos;
    *infos = info;
}