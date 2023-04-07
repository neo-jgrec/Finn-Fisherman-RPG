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
    #include "mars.h"

    #define IS_WHITESPACE(c) (c == ' ' || c == '\t' || c == '\n' || c == '\r')
    #define SEMICOLON ;
    #define TAILQ_FOREACH_SAFE(var, head, field, tvar) \
        for ((var) = TAILQ_FIRST((head))SEMICOLON \
            (var) && ((tvar) = TAILQ_NEXT((var), field), 1)SEMICOLON \
            (var) = (tvar))

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

/**
 * @brief Save the xml tree to a file
 *
 * @param parser  The xml parser
 * @param filename  The file to save to
 */
void save_xml(xml_parser_t *parser, const char *filename);

/**
 * @brief Get the value of a node by its tags from the root
 *      The tags are the names of the nodes from the root to the node
 *      Example: char *tags[] = {"root", "child", "grandchild", NULL};
 *
 * @param root  The root node
 * @param tags  The tags of the node
 * @return char*  The value of the node
 */
void update_value_by_tags(xml_node_t *root, char **tags, const char *new_value);

/**
 * @brief free all the memory used by the parser
 *
 * @param parser
 */
void free_parser(xml_parser_t *parser);

/**
 * @brief Initialize the parser thanks to a file
 * 
 * @param filename
 * @return xml_parser_t*
 */
xml_parser_t *init_parser(char *filename);

/**
 * @brief Parse a node
 *      The user should not call this function
 * @param parser
 * @param is_root
 * @return xml_node_t*
 */
xml_node_t *parse_node(xml_parser_t *parser, int is_root);

#endif /* !XML_PARSER_H_ */
