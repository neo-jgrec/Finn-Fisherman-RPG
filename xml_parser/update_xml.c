/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_xml
*/

#include "xml_parser.h"

void write_node_value(FILE *file, xml_node_t *node)
{
    if (node->value) {
        size_t value_len = my_strlen(node->value);
        fwrite(node->value, sizeof(char), value_len, file);
    }
}

void write_node(FILE *file, xml_node_t *node)
{
    if (node->name) {
        size_t name_len = my_strlen(node->name);
        fwrite("<", sizeof(char), 1, file);
        fwrite(node->name, sizeof(char), name_len, file);
        fwrite(">", sizeof(char), 1, file);
    }
    write_node_value(file, node);
    xml_node_t *child;
    TAILQ_FOREACH(child, &node->children, next) {
        write_node(file, child);
    }
    if (node->name) {
        size_t name_len = my_strlen(node->name);
        fwrite("</", sizeof(char), 2, file);
        fwrite(node->name, sizeof(char), name_len, file);
        fwrite(">", sizeof(char), 1, file);
    }
}

void save_xml(xml_parser_t *parser, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (!file) {
        my_printf("Error opening file\n");
        return;
    }
    write_node(file, parser->root);
    fclose(file);
}
