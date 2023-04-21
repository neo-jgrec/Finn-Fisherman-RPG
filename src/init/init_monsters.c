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
    VEC pos = {0};
    int type = 0;

    if (stw == NULL)
        return;
    for (; stw[len]; len++);
    if (len != 3)
        return;
    type = my_atoi(stw[0]);
    pos.x = my_atoi(stw[1]);
    pos.y = my_atoi(stw[2]);
    add_monster(rpg, type, pos);
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
    stw = a_mkstw(monsters, "\n");
    if (stw == NULL)
        return;
    for (int i = 0; stw[i]; i++)
        init_a_monster(rpg, stw[i]);
    a_freestw(stw);
}
