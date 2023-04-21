/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** get_xml_int
*/

#include "rpg.h"

int get_xml_int(xml_parser_t *parser, char **tags)
{
    char *str = NULL;

    str = get_value_by_tags(parser->root, tags);
    if (str == NULL)
        return 0;
    return my_atoi(str);
}
