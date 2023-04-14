/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_map
*/

#include "rpg.h"

int init_map(char *path, puzzle_t *puzzle)
{
    xml_parser_t *parser = init_parser(path);
    char *map = NULL;
    char *foreground = NULL;
    char *background = NULL;

    parse_xml(parser);
    map = get_value_by_tags(parser->root, (char *[]){"MAP", NULL});
    foreground = get_value_by_tags(parser->root,
        (char *[]){"FOREGROUND", NULL});
    background = get_value_by_tags(parser->root,
        (char *[]){"BACKGROUND", NULL});
    puzzle->map = map_parsing(map);
    puzzle->background = map_parsing(background);
    puzzle->foreground = map_parsing(foreground);
    free_parser(parser);
    return 0;
}
