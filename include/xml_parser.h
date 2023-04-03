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

#endif /* !XML_PARSER_H_ */
