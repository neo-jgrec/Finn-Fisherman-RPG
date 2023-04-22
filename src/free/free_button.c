/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free_button
*/

#include "rpg.h"

void free_button(struct buttons *button_list)
{
    button_t *button = NULL;
    button_t *tmp = NULL;

    TAILQ_FOREACH_SAFE(button, button_list, next, tmp) {
        TAILQ_REMOVE(button_list, button, next);
        sfRectangleShape_destroy(button->shape);
        free(button);
    }
}
