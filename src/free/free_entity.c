/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** free_entity
*/

#include "rpg.h"

void free_entity(entity_t *entity)
{
    if (entity->health.lvl_hud != NULL)
        sfText_destroy(entity->health.lvl_hud);
    if (entity->drop_list != NULL)
        free(entity->drop_list);
    free(entity);
}
