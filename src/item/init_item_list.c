/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_item_list
*/

#include "rpg.h"

static player_stat_t init_item_stat(char **stw)
{
    player_stat_t stat = {0};

    stat.max_potion = my_atoi(stw[2]);
    stat.heal_power = my_atoi(stw[3]);
    stat.max_health = my_atoi(stw[4]);
    stat.speed = my_atoi(stw[5]);
    stat.damage = my_atoi(stw[6]);
    stat.crit_chance = my_atoi(stw[7]);
    stat.jump = my_atoi(stw[8]);
    return stat;
}

static item_e create_item(char *str)
{
    item_e item = {0};
    int len = 0;
    char **stw = a_mkstw(str, ":");

    if (stw == NULL)
        return item;
    for (; stw[len]; len++);
    if (len != 10)
        return item;
    item.desc = my_strdup(stw[9]);
    item.equiped = 0;
    item.in_inventory = 0;
    item.next = NULL;
    item.pos = (VEC){0};
    item.type = my_atoi(stw[0]);
    item.sprite = my_atoi(stw[1]);
    item.item_stat = init_item_stat(stw);
    a_freestw(stw);
    return item;
}

static item_e *create_item_tab(rpg_t *rpg, char **stw)
{
    int nb = 0;
    item_e *item_list = NULL;

    for (; stw[nb]; nb++);
    if ((item_list = malloc(sizeof(item_e) * nb)) == NULL)
        return NULL;
    rpg->data->nb_item = nb;
    for (int i = 0; i < nb; i++)
        item_list[i] = create_item(stw[i]);
    return item_list;
}

void init_item_list(rpg_t *rpg)
{
    xml_parser_t *parser = init_parser("game_file/items.xml");
    char **stw = NULL;
    char *str = NULL;

    if (parser == NULL)
        return;
    parse_xml(parser);
    str = get_value_by_tags(parser->root, (char *[]){"ITEMS", NULL});
    if (str == NULL)
        return;
    stw = a_mkstw(str, ",");
    if (stw == NULL)
        return;
    rpg->data->nb_item = 0;
    rpg->data->item_list = create_item_tab(rpg, stw);
    a_freestw(stw);
}
