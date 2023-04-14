/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** add_monster
*/

#include "rpg.h"

void add_monster(rpg_t *rpg, entity_t **monsters, id_t id, VEC pos)
{
    entity_t *monster = malloc(sizeof(entity_t));

    if (monster == NULL)
        return;
    if (id == MONSTER_1)
        init_monster_1(rpg, rpg->asset, monster, pos);
    if (monsters == NULL) {
        monsters = &monster;
        return;
    }
    monster->next = *monsters;
    *monsters = monster;
}
