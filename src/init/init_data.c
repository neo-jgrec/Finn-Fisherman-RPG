/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_data
*/

#include "rpg.h"

static item_e *init_inventory(void)
{
    item_e *inv = malloc(sizeof(item_e) * 3 * 9);

    if (inv == NULL)
        return NULL;
    return inv;
}

static void default_data(rpg_t *rpg, data_t *data)
{
    data->location = 0;
    data->player_stat = (player_stat_t){2, 75, 200, 400, 50, 50};
    data->item_stat = (player_stat_t){0};
    data->jump = get_xml_int(data->parser, (char *[]){"STATS", "JUMP", NULL});
    data->lvl = 14;
    data->xp = 20;
    data->xp_to_lvl_up = 100;
    data->lvl_point = 0;
}

static void get_data(rpg_t *rpg, data_t *data)
{
    data->parser = init_parser(rpg->save_path);

    if (data->parser == NULL)
        data = NULL;
    parse_xml(data->parser);
    default_data(rpg, data);
}

void init_data(rpg_t *rpg)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL)
        rpg->puzzle = NULL;
    get_data(rpg, data);
    rpg->data = data;
    loading_screen(rpg, rpg->loading, 45, 0);
}
