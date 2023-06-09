/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** parser
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "xml_parser.h"

void read_value(xml_parser_t *parser, xml_node_t *node)
{
    char *value_start = parser->buffer_ptr;

    while (*parser->buffer_ptr != '<'
    && parser->buffer_ptr < parser->buffer_end)
        parser->buffer_ptr++;
    if (value_start == parser->buffer_ptr) {
        node->value = my_strdup("");
    } else
        node->value = my_strndup(value_start, parser->buffer_ptr - value_start);
}

static void realloc_buffer(xml_parser_t *parser, size_t bytes_read_total,
size_t buffer_size)
{
    void *tmp = memset(malloc(buffer_size), 0, buffer_size);

    my_memcpy(tmp, parser->buffer, bytes_read_total);
    free(parser->buffer);
    parser->buffer = tmp;
}

void parse_xml(xml_parser_t *parser)
{
    FILE *file = fopen(parser->filename, "r");
    size_t buffer_size = 4096;
    size_t bytes_read_total = 0, bytes_read_current = 0;

    if (!file) return;
    parser->buffer = malloc(buffer_size);
    while ((bytes_read_current = fread(parser->buffer + bytes_read_total,
    1, buffer_size - bytes_read_total, file)) > 0) {
        bytes_read_total += bytes_read_current;
        if (bytes_read_total == buffer_size) {
            buffer_size *= 2;
            realloc_buffer(parser, bytes_read_total, buffer_size);
        }
    }
    fclose(file);
    parser->buffer[bytes_read_total] = '\0';
    parser->buffer_ptr = parser->buffer;
    parser->buffer_end = parser->buffer + bytes_read_total;
    parser->root = parse_node(parser, 1);
}

char *get_value_by_tags(xml_node_t *root, char **tags)
{
    if (!root || !tags || !*tags)
        return NULL;

    xml_node_t *child;
    TAILQ_FOREACH(child, &root->children, next) {
        if (my_strcmp(child->name, *tags) == 0) {
            if (*(tags + 1) == NULL) {
                return child->value;
            } else {
                return get_value_by_tags(child, tags + 1);
            }
        }
    }
    return NULL;
}
