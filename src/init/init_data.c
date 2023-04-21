/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_data
*/

#include "rpg.h"

static item_e **init_inventory(void)
{
    item_e **inv = malloc(sizeof(item_e *) * 3 * 9);

    if (inv == NULL)
        return NULL;
    for (int i = 0; i < 3 * 9; i++) {
        inv[i] = NULL;
    }
    return inv;
}

static void default_data(data_t *data)
{
    data->location = 0;
    data->player_stat = (player_stat_t){2, 75, 200, 400, 50, 50, 6};
    data->item_stat = (player_stat_t){0};
    data->tot_stat = (player_stat_t){0};
    data->lvl = 14;
    data->xp = 20;
    data->xp_to_lvl_up = 100;
    data->lvl_point = 0;
    data->inventory = init_inventory();
}

static void get_data(data_t *data)
{
    data->parser = NULL;
    default_data(data);
}

void init_data(rpg_t *rpg)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL)
        rpg->puzzle = NULL;
    get_data(data);
    rpg->data = data;
    loading_screen(rpg, rpg->loading, 45, 0);
}
