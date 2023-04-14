/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** edit_value
*/

#include "xml_parser.h"

void update_value_by_tags(xml_node_t *root, char **tags, const char *new_value)
{
    xml_node_t *child;

    if (!root || !tags || !*tags)
        return;
    TAILQ_FOREACH(child, &root->children, next) {
        if (my_strcmp(child->name, *tags) == 0) {
            (*(tags + 1) == NULL) ? ({
                free(child->value);
                child->value = my_strdup(new_value);
                return;
            }) : ({
                update_value_by_tags(child, tags + 1, new_value);
            });
        }
    }
}
