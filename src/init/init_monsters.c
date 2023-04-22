/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_monsters
*/

#include "rpg.h"

static void init_a_monster(rpg_t *rpg, char *monster)
{
    char **stw = a_mkstw(monster, ":");
    int len = 0;
    monster_stat_t stat = {0};
    int type = 0;

    if (stw == NULL)
        return;
    for (; stw[len]; len++);
    if (len != 7)
        return;
    type = my_atoi(stw[0]);
    stat.pos.x = my_atoi(stw[1]);
    stat.pos.y = my_atoi(stw[2]);
    stat.damage = my_atoi(stw[3]);
    stat.life = my_atoi(stw[4]);
    stat.loot = my_atoi(stw[5]);
    stat.drop_list = my_strdup(stw[6]);
    add_monster(rpg, type, stat);
    a_freestw(stw);
}

void init_monsters(rpg_t *rpg)
{
    xml_parser_t *parser = rpg->puzzle->parser;
    char *monsters = get_value_by_tags(parser->root,
        (char *[]){"MONSTERS", NULL});
    char **stw = NULL;

    if (monsters == NULL)
        return;
    stw = a_mkstw(monsters, "\n ");
    if (stw == NULL)
        return;
    for (int i = 0; stw[i]; i++)
        init_a_monster(rpg, stw[i]);
    a_freestw(stw);
}
