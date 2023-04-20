/*
** EPITECH PROJECT, 2023
** free_quest
** File description:
** free_quest
*/

#include "rpg.h"

static void free_quest_lst_elms(quest_t *quest)
{
    quest_s *temp = quest->tail;

    while (temp->prev){
        free(temp->dialogue);
        free(temp->name_npc);
        free(temp->q_desc);
        free(temp->requirement.requirement);
        free(temp->xml_npc);
        temp = temp->prev;
        free(temp->next);
    }
    free(temp->dialogue);
    free(temp->name_npc);
    free(temp->q_desc);
    free(temp->requirement.requirement);
    free(temp->xml_npc);
    free(temp);
}

void free_quest(quest_t *quest)
{
    if (quest){
        if (quest->tail) {
            free_quest_lst_elms(quest);
        }
        free(quest);
    }
}
