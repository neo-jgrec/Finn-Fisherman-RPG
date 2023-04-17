/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** add_monster
*/

#include "rpg.h"

void add_monster(rpg_t *rpg, id_entity id, VEC pos)
{
    entity_t **monsters = rpg->monsters;
    entity_t *monster = malloc(sizeof(entity_t));

    if (monster == NULL)
        return;
    if (id == SKELETON)
        init_skeleton(rpg, monster, pos);
    if (id == EYE)
        init_eye(rpg, monster, pos);
    monster->next = *monsters;
    *monsters = monster;
}
