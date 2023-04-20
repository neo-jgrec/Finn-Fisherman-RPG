/*
** EPITECH PROJECT, 2023
** init_quest
** File description:
** init_quest
*/

#include "rpg.h"

void init_quest(rpg_t *rpg)
{
    quest_t *quests = malloc(sizeof(quest_t));

    rpg->quests = NULL;
    if (!quests)
        return;
    quests->head = NULL;
    quests->tail = NULL;
    quests->size = 0;
    rpg->quests = quests;
}
