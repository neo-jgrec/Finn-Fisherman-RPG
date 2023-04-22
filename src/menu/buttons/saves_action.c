/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** saves_action
*/

#include "rpg.h"

static player_stat_t default_stat(data_t *data)
{
    player_stat_t pstat = {0};
    pstat.crit_chance = get_xml_int(data->parser,
        (char *[]){"STATS", "CRIT_CHANCE", NULL});
    pstat.damage = get_xml_int(data->parser,
        (char *[]){"STATS", "DAMAGE", NULL});
    pstat.speed = get_xml_int(data->parser,
        (char *[]){"STATS", "SPEED", NULL});
    pstat.max_health = get_xml_int(data->parser,
        (char *[]){"STATS", "MAX_HEALTH", NULL});
    pstat.max_potion = get_xml_int(data->parser,
        (char *[]){"STATS", "POTION", "MAX_POTION", NULL});
    pstat.heal_power = get_xml_int(data->parser,
        (char *[]){"STATS", "POTION", "HEALTH_POWER", NULL});
    pstat.jump = get_xml_int(data->parser,
        (char *[]){"STATS", "JUMP", NULL});
    return pstat;
}

static void default_data(data_t *data)
{
    data->location = get_xml_int(data->parser,
        (char *[]){"LOCATION", NULL});;
    data->player_stat = (player_stat_t){0};
    data->item_stat = (player_stat_t){0};
    data->lvl = get_xml_int(data->parser,
        (char *[]){"STATS", "LEVEL", NULL});
    data->xp = get_xml_int(data->parser,
        (char *[]){"STATS", "EXP", NULL});
    data->xp_to_lvl_up = get_xml_int(data->parser,
        (char *[]){"STATS", "EXP_TO_NEXT_LEVEL", NULL});
    data->lvl_point = get_xml_int(data->parser,
        (char *[]){"STATS", "LVL_POINT", NULL});
    data->player_stat = default_stat(data);
    init_inventory_equiped(data);
}

void launch_game(rpg_t *rpg)
{
    rpg->save_path = rpg->menu->selected_save;
    rpg->data->parser = init_parser(rpg->save_path);
    parse_xml(rpg->data->parser);
    default_data(rpg->data);
    init_puzzle(rpg);
    free_items(rpg);
    free_monsters(rpg);
    init_monsters(rpg);
    save_data(rpg);
    switch_weather(rpg);
    rpg->win->scene = GAME;
}
