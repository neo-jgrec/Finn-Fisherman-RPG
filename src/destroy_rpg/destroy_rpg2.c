/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** destroy_rpg2
*/

#include "rpg.h"

void free_loading(rpg_t *rpg)
{
    free_sprite_t(rpg->loading->fishs[0]);
    free_sprite_t(rpg->loading->fishs[1]);
    free(rpg->loading->fishs);
    free_sprite_t(rpg->loading->youdead);
    free(rpg->loading);
}

void free_player(rpg_t *rpg)
{
    sfText_destroy(rpg->player->health.lvl_hud);
    free(rpg->player);
    free(rpg->parall->layers);
    free(rpg->parall->pos);
    free(rpg->parall);
}

void free_data(rpg_t *rpg)
{
    free(rpg->data->inventory);
    if (rpg->data->item_list)
        free(rpg->data->item_list);
    free(rpg->data);
}
