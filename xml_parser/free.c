/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free
*/

#include "xml_parser.h"

void free_node(xml_node_t *node)
{
    xml_node_t *child, *tmp;
    TAILQ_FOREACH_SAFE(child, &node->children, next, tmp) {
        TAILQ_REMOVE(&node->children, child, next);
        free_node(child);
    }
    free(node->name);
    free(node->value);
    free(node);
}

void free_parser(xml_parser_t *parser)
{
    free_node(parser->root);
    free(parser->buffer);
    free(parser);
}
