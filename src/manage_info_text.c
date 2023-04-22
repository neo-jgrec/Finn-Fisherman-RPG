/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_info_text
*/

#include "rpg.h"

static void manage_delete_info_text(rpg_t *rpg)
{
    info_t *node = *rpg->infos;
    info_t *prev = NULL;
    int count = 0;

    for (; node != NULL; node = node->next) {
        if (node->cd < 0 && count != 0)
            prev->next = node->next;
        if (node->cd < 0 && count == 0)
            *rpg->infos = node->next;
        if (node->cd >= 0) {
            count++;
            prev = node;
        }
    }
}

void manage_info_text(rpg_t *rpg)
{
    manage_delete_info_text(rpg);
    info_t **infos = rpg->infos;

    for (info_t *node = *infos; node; node = node->next) {
        node->cd -= rpg->win->deltaT;
        node->pos.y += rpg->win->deltaT * 16;
    }
}