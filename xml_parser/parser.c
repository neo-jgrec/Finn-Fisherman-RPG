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

xml_parser_t *init_parser(char *filename) {
    xml_parser_t *parser = malloc(sizeof(xml_parser_t));

    parser->filename = filename;
    parser->buffer = NULL;
    parser->buffer_ptr = NULL;
    parser->buffer_end = NULL;
    parser->root = malloc(sizeof(xml_node_t));
    return (parser);
}

char *custom_strndup(const char *s, size_t n) {
    size_t len = strnlen(s, n);
    char *new_str = malloc(len + 1);
    if (new_str) {
        memcpy(new_str, s, len);
        new_str[len] = '\0';
    }
    return new_str;
}

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void skip_whitespace(xml_parser_t *parser) {
    while (parser->buffer_ptr < parser->buffer_end && is_whitespace(*parser->buffer_ptr))
        parser->buffer_ptr++;
}

void read_value(xml_parser_t *parser, xml_node_t *node) {
    char *value_start = parser->buffer_ptr;
    while (*parser->buffer_ptr != '<' && parser->buffer_ptr < parser->buffer_end)
        parser->buffer_ptr++;
    if (value_start == parser->buffer_ptr) {
        node->value = strdup("");
    } else {
        node->value = custom_strndup(value_start, parser->buffer_ptr - value_start);
    }
}

xml_node_t *parse_node(xml_parser_t *parser, int is_root);

void add_child(xml_parser_t *parser, xml_node_t *parent) {
    xml_node_t *child = parse_node(parser, 0);
    if (child)
        TAILQ_INSERT_TAIL(&parent->children, child, next);
}

xml_node_t *parse_node(xml_parser_t *parser, int is_root) {
    if (parser->buffer_ptr >= parser->buffer_end)
        return NULL;

    xml_node_t *node = malloc(sizeof(xml_node_t));
    TAILQ_INIT(&node->children);

    // Skip opening '<'
    parser->buffer_ptr++;
    char *name_start = parser->buffer_ptr;
    while (*parser->buffer_ptr != '>' && parser->buffer_ptr < parser->buffer_end)
        parser->buffer_ptr++;
    node->name = custom_strndup(name_start, parser->buffer_ptr - name_start);

    // Skip closing '>'
    parser->buffer_ptr++;
    skip_whitespace(parser);

    if (!is_root) {
        read_value(parser, node);
    } else {
        node->value = NULL;
    }
    skip_whitespace(parser);

    // Check for nested nodes
    while (*parser->buffer_ptr == '<' && *(parser->buffer_ptr + 1) != '/') {
        add_child(parser, node);
        skip_whitespace(parser);
    }

    // Skip closing tag
    parser->buffer_ptr += 2 + strlen(node->name) + 1;
    skip_whitespace(parser);

    return node;
}

void parse_xml(xml_parser_t *parser) {
    FILE *file = fopen(parser->filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    parser->buffer = malloc(file_size + 1);
    fread(parser->buffer, 1, file_size, file);
    fclose(file);

    parser->buffer[file_size] = '\0';
    parser->buffer_ptr = parser->buffer;
    parser->buffer_end = parser->buffer + file_size;

    parser->root = parse_node(parser, 1);
}

void free_node(xml_node_t *node) {
    xml_node_t *child, *tmp;
    TAILQ_FOREACH_SAFE(child, &node->children, next, tmp) {
        TAILQ_REMOVE(&node->children, child, next);
        free_node(child);
    }
    free(node->name);
    free(node->value);
    free(node);
}

void free_parser(xml_parser_t *parser) {
    free_node(parser->root);
    free(parser->buffer);
    free(parser);
}

char *get_value_by_tags(xml_node_t *root, char **tags) {
    if (!root || !tags || !*tags)
        return NULL;

    xml_node_t *child;
    TAILQ_FOREACH(child, &root->children, next) {
        if (strcmp(child->name, *tags) == 0) {
            if (*(tags + 1) == NULL) {
                return child->value;
            } else {
                return get_value_by_tags(child, tags + 1);
            }
        }
    }
    return NULL;
}

int main() {
    xml_parser_t *parser = init_parser("assets/inventory.xml");
    parse_xml(parser);

    char *inventory_name = parser->root->name;
    printf("Inventory Name: %s\n", inventory_name);

    char *item2_name = get_value_by_tags(parser->root, (char *[]){ "ITEM2", "NAME", NULL });
    if (item2_name) {
        printf("Item 2 Name: %s\n", item2_name);
    }

    free_parser(parser);
    return 0;
}