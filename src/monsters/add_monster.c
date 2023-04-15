/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** add_monster
*/

#include "rpg.h"

void add_monster(rpg_t *rpg, id_t id, VEC pos)
{
    entity_t **monsters = rpg->monsters;
    entity_t *monster = malloc(sizeof(entity_t));

    if (monster == NULL)
        return;
    if (id == MONSTER_1)
        init_monster_1(rpg, monster, pos);
    monster->next = *monsters;
    *monsters = monster;
}
