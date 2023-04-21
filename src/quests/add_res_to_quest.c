/*
** EPITECH PROJECT, 2023
** add_res_to_quest
** File description:
** add_res_to_quest
*/

#include "rpg.h"

void add_res_to_quest(quest_t *quest, char *quest_type)
{
    quest_s *temp = quest->head;

    for (; temp; temp = temp->next) {
        if (my_strcmp(temp->requirement.requirement, quest_type) == 0 &&
        temp->state == 0) {
            temp->requirement.number_get += 1;
            sfText_setString(temp->desc.quest, get_quest_advancement(temp));
        }
    }
}
