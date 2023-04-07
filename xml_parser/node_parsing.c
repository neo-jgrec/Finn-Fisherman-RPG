/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** node_parsing
*/

#include "xml_parser.h"
void skip_whitespace(xml_parser_t *parser);
void read_value(xml_parser_t *parser, xml_node_t *node);

static xml_node_t *create_new_node(UNUSED xml_parser_t *parser)
{
    xml_node_t *node = malloc(sizeof(xml_node_t));
    TAILQ_INIT(&node->children);
    return node;
}

static void set_node_name(xml_parser_t *parser, xml_node_t *node)
{
    char *name_start = parser->buffer_ptr;
    while (*parser->buffer_ptr != '>'
    && parser->buffer_ptr < parser->buffer_end)
        parser->buffer_ptr++;
    node->name = my_strndup(name_start, parser->buffer_ptr - name_start);
}

static void add_child(xml_parser_t *parser, xml_node_t *parent)
{
    xml_node_t *child = parse_node(parser, 0);
    if (child)
        TAILQ_INSERT_TAIL(&parent->children, child, next);
}

static void process_children(xml_parser_t *parser, xml_node_t *node)
{
    while (*parser->buffer_ptr == '<' && *(parser->buffer_ptr + 1) != '/') {
        add_child(parser, node);
        skip_whitespace(parser);
    }
}

xml_node_t *parse_node(xml_parser_t *parser, int is_root)
{
    if (parser->buffer_ptr >= parser->buffer_end)
        return NULL;
    xml_node_t *node = create_new_node(parser);
    parser->buffer_ptr++;
    set_node_name(parser, node);
    parser->buffer_ptr++;
    skip_whitespace(parser);
    if (!is_root)
        read_value(parser, node);
    else
        node->value = NULL;
    skip_whitespace(parser);
    process_children(parser, node);
    parser->buffer_ptr += 2 + my_strlen(node->name) + 1;
    skip_whitespace(parser);
    return node;
}
