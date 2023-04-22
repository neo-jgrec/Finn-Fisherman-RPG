/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_info_text
*/

#include "rpg.h"

static void draw_info_text(rpg_t *rpg, info_t *info)
{
    info->cd -= rpg->win->deltaT;
    sfText_setPosition(rpg->info_text, info->pos);
    sfText_setString(rpg->info_text, info->str);
    sfText_setColor(rpg->info_text, info->color);
    sfRenderWindow_drawText(rpg->win->win, rpg->info_text, NULL);
}

void draw_infos_text(rpg_t *rpg)
{
    info_t **infos = rpg->infos;

    for (info_t *node = *infos; node; node = node->next) {
        draw_info_text(rpg, node);
    }
}
