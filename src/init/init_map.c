/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_map
*/

#include "rpg.h"

static sfVector2f init_spawn(xml_parser_t *parser)
{
    int x = 0;
    int y = 0;
    char *buff_x = NULL;
    char *buff_y = NULL;

    buff_x = get_value_by_tags(parser->root,
        (char *[]){"SPAWN", "X", NULL});
    x = my_atoi(buff_x);
    buff_y = get_value_by_tags(parser->root,
        (char *[]){"SPAWN", "Y", NULL});
    y = my_atoi(buff_y);
    return (VEC){x, y};
}

static void init_map_2(xml_parser_t *parser, puzzle_t *puzzle)
{
    char *death = NULL;

    death = get_value_by_tags(parser->root,
        (char *[]){"DEATH", NULL});
    puzzle->death = map_parsing(death);
}

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
    puzzle->spawn = init_spawn(parser);
    init_map_2(parser, puzzle);
    init_fish_spot(puzzle, parser);
    free_parser(parser);
    return 0;
}
