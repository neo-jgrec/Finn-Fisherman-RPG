/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** xml_parser
*/

#ifndef XML_PARSER_H_
    #define XML_PARSER_H_

    #include <sys/queue.h>
    #include <malloc.h>
<<<<<<< HEAD
    #include "mars.h"

    #define IS_WHITESPACE(c) (c == ' ' || c == '\t' || c == '\n' || c == '\r')

    #define TAILQ_FOREACH_SAFE(var, head, field, tvar) \
        for ((var) = TAILQ_FIRST((head)); \
            (var) && ((tvar) = TAILQ_NEXT((var), field), 1); \
            (var) = (tvar))
=======
>>>>>>> 62e30ac (feat(main) first addition of xml_parsing)

typedef struct xml_node {
    char *name;
    char *value;
    TAILQ_HEAD(xml_node_list, xml_node) children;
    TAILQ_ENTRY(xml_node) next;
} xml_node_t;

typedef struct xml_parser {
    char *filename;
    char *buffer;
    char *buffer_ptr;
    char *buffer_end;
    xml_node_t *root;
} xml_parser_t;

void save_xml(xml_parser_t *parser, const char *filename);
void update_value_by_tags(xml_node_t *root, char **tags, const char *new_value);
void free_parser(xml_parser_t *parser);
xml_parser_t *init_parser(char *filename);
xml_node_t *parse_node(xml_parser_t *parser, int is_root);

#endif /* !XML_PARSER_H_ */
