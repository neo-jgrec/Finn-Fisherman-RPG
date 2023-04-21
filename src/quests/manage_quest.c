/*
** EPITECH PROJECT, 2023
** manage_quest
** File description:
** manage_quest
*/

#include "rpg.h"

static void verify_pos_in_dialogue(char **dialogue, quest_s *quest)
{
    if (!dialogue[PARSER + 1]) {
        PARSER = 0;
        sfText_setString(quest->text, dialogue[PARSER]);
        quest->dialogue.is_talking = false;
        return;
    }
    sfText_setString(quest->text, dialogue[PARSER + 1]);
    quest->dialogue.parser++;
}

static void change_text(quest_s *quest)
{
    if (quest->state == 0 && quest->requirement.number_get <
    quest->requirement.number_req)
        verify_pos_in_dialogue(quest->dialogue.dialogue, quest);
    if (quest->state == 0 && quest->requirement.number_get >=
    quest->requirement.number_req)
        verify_pos_in_dialogue(quest->dialogue.dialogue_complete, quest);
    if (quest->state == 1)
        verify_pos_in_dialogue(quest->dialogue.dialogue_finish, quest);
}

static void manage_quest(quest_s *quest, win_t *win)
{
    quest->dialogue.clock_dialogue += win->deltaT;
    if (quest->dialogue.clock_dialogue > 3) {
        change_text(quest);
        quest->dialogue.clock_dialogue = 0;
    }
}

void display_npc_dialogue(quest_t *quest, rpg_t *rpg)
{
    quest_s *temp = quest->head;

    for (; temp; temp = temp->next) {
        if (temp->dialogue.is_talking)
            manage_quest(temp, rpg->win);
    }
}
