/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_info_text
*/

#include "rpg.h"

static void free_info_text(info_t *to_free, rpg_t *rpg)
{
    info_t *node = *rpg->infos;
    info_t *prev = NULL;

    for (; node != NULL;) {
        prev = node;
        node = node->next;
        if (node == to_free) {
            prev->next = to_free->next;
            free(to_free->str);
            free(to_free);
            break;
        }
    }
}

static void manage_delete_info_text(rpg_t *rpg)
{
    info_t *node = *rpg->infos;
    info_t *prev = NULL;

    for (; node != NULL; node = node->next) {
        prev = node;
    }
    if (prev == NULL || prev->cd >= 0)
        return;
    if (prev == *rpg->infos)
        *rpg->infos = prev->next;
    else
        free_info_text(prev, rpg);
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
