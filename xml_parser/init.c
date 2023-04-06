/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init
*/

#include "xml_parser.h"

xml_parser_t *init_parser(char *filename)
{
    xml_parser_t *parser = malloc(sizeof(xml_parser_t));

    parser->filename = filename;
    parser->buffer = NULL;
    parser->buffer_ptr = NULL;
    parser->buffer_end = NULL;
    parser->root = malloc(sizeof(xml_node_t));
    return (parser);
}
