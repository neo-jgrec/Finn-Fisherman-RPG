/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** add_monster
*/

#include "rpg.h"

void add_monster(rpg_t *rpg, id_entity id, monster_stat_t stat)
{
    entity_t **monsters = rpg->monsters;
    entity_t *monster = malloc(sizeof(entity_t));

    if (monster == NULL)
        return;
    if (id == SKELETON)
        init_skeleton(rpg, monster, stat);
    if (id == EYE)
        init_eye(rpg, monster, stat);
    if (id == SHROOM)
        init_shroom(rpg, monster, stat);
    if (id == TROLL)
        init_troll(rpg, monster, stat);
    if (id == BALL)
        init_ball(rpg, monster, stat);
    if (id == SLASH)
        init_slash(rpg, monster, stat);
    monster->next = *monsters;
    *monsters = monster;
}
