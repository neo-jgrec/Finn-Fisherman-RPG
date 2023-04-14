/*
** EPITECH PROJECT, 2023
** init_fishing
** File description:
** init_fishing
*/

#include "rpg.h"

static sfRectangleShape *init_rect_bar(rpg_t *rpg)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    if (rectangle == NULL)
        return (NULL);
    sfRectangleShape_setSize(rectangle, (sfVector2f){30, 100});
    sfRectangleShape_setPosition(rectangle, (sfVector2f){
    rpg->win->size.x / 2, rpg->win->size.y / 2});
    sfRectangleShape_setFillColor(rectangle, sfGreen);
    return (rectangle);
}

void init_fishing(rpg_t *rpg)
{
    fishing_t *fishing = NULL;

    if (!(fishing = malloc(sizeof(fishing_t)))) {
        rpg->fishing = NULL;
        return;
    }
    fishing->font = NULL;
    fishing->fish = NULL;
    fishing->fish_bar = init_rect_bar(rpg);
    fishing->state = false;
    fishing->clock = 0;
    rpg->fishing = fishing;
}
