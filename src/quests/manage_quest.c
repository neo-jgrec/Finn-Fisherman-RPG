/*
** EPITECH PROJECT, 2023
** manage_quest
** File description:
** manage_quest
*/

#include "rpg.h"

static void verify_pos_in_dialogue(char **dialogue, quest_s *quest)
{
    if (!dialogue[PARSER]) {
        PARSER = 0;
        quest->dialogue.is_talking = false;
        return;
    }
    sfText_setString(quest->text, dialogue[PARSER]);
    quest->dialogue.parser++;
}

static void change_text(quest_s *quest)
{
    if (quest->state == -1) {
        verify_pos_in_dialogue(quest->dialogue.dialogue, quest);
        if (!quest->dialogue.is_talking)
            quest->state = 0;
        return;
    } if (quest->state == 0 && quest->requirement.number_get <
    quest->requirement.number_req) {
        verify_pos_in_dialogue(quest->dialogue.dialogue, quest);
        return;
    } if (quest->state == 0 && quest->requirement.number_get >=
    quest->requirement.number_req) {
        verify_pos_in_dialogue(quest->dialogue.dialogue_complete, quest);
        if (!quest->dialogue.is_talking)
            quest->state = 1;
        return;
    } if (quest->state == 1) {
        verify_pos_in_dialogue(quest->dialogue.dialogue_finish, quest);
        return;
    }
}

static bool set_beg(quest_s *quest, rpg_t *rpg)
{
    if (PARSER != 0)
        return false;
    if (quest->state == -1 || (quest->state == 0 &&
    quest->requirement.number_get < quest->requirement.number_req))
        sfText_setString(quest->text, quest->dialogue.dialogue[PARSER]);
    if (quest->state == 0 && quest->requirement.number_get >=
    quest->requirement.number_req) {
        add_item(rpg, 0, (VEC){rpg->player->pos.x + 40,
            rpg->player->pos.y - 50});
        sfText_setString(quest->text,
        quest->dialogue.dialogue_complete[PARSER]);
    }
    if (quest->state == 1)
        sfText_setString(quest->text,
        quest->dialogue.dialogue_finish[PARSER]);
    PARSER++;
    return true;
}

static void manage_quest(quest_s *quest, win_t *win, rpg_t *rpg)
{
    quest->dialogue.clock_dialogue += win->deltaT;
    if (set_beg(quest, rpg)) {
        quest->dialogue.clock_dialogue = 0;
        return;
    }
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
            manage_quest(temp, rpg->win, rpg);
    }
}
