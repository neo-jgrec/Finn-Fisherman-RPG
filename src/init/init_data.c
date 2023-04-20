/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_data
*/

#include "rpg.h"

item_e *init_inventory(void)
{
    item_e *inv = malloc(sizeof(item_e) * 3 * 9);

    if (inv == NULL)
        return NULL;
    return inv;
}

void init_data(rpg_t *rpg)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL)
        rpg->puzzle = NULL;
    data->player_stat = (player_stat_t){2, 75, 200, 400, 50, 50};
    data->item_stat = (player_stat_t){0};
    data->jump = 6;
    data->roll = 1;
    data->fishing = 1;
    data->attack = 1;
    data->lvl = 14;
    data->xp = 20;
    data->xp_to_lvl_up = 100;
    data->lvl_point = 0;
    rpg->data = data;
    loading_screen(rpg, rpg->loading, 45, 0);
}
