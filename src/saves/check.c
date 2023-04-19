/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check
*/

#include "rpg.h"
#include <fcntl.h>

static char *needed_tags[][4] = {
    {"STATS", NULL},
    {"SAVENAME", NULL},
    {"LOCATION", NULL},
    {"STARTED", NULL},
    {"STATS", "POTION", NULL},
    {"STATS", "POTION", "MAX_POTION", NULL},
    {"STATS", "POTION", "HEALTH_POWER", NULL},
    {"STATS", "MAX_HEALTH", NULL},
    {"STATS", "SPEED", NULL},
    {"STATS", "DAMAGE", NULL},
    {"STATS", "CRIT_CHANCE", NULL},
    {"STATS", "JUMP", NULL},
    {"STATS", "ROLL", NULL},
    {"STATS", "FISHING", NULL},
    {"STATS", "ATTACK", NULL},
    {"STATS", "LEVEL", NULL},
    {"STATS", "EXP", NULL},
    {"STATS", "EXP_TO_NEXT_LEVEL", NULL}
};

bool are_tags_in_file(char *filename)
{
    xml_parser_t *parser = init_parser(filename);
    size_t i = 0;

    parse_xml(parser);
    for (i = 0; i < 18; i++) {
        if (!get_value_by_tags(parser->root, needed_tags[i]))
            return false;
    }
    return true;
}
