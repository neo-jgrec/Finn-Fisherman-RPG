/*
** EPITECH PROJECT, 2023
** npc_interraction
** File description:
** npc_interraction
*/

#include "rpg.h"

static void init_dialogue(npc_lt *npc, quest_s *quest)
{
    if (!quest->dialogue.is_talking && quest->dialogue.parser == 0) {
        quest->dialogue.is_talking = true;
        sfText_setString(quest->text, quest->dialogue.dialogue[PARSER]);
        sfText_setPosition(quest->text, (sfVector2f){POS_NPC.x - 20,
        POS_NPC.y - 30});
        quest->state = 0;
    }
}

static void change_npc_dialogue_state(npc_lt *npc, quest_t *quest)
{
    quest_s *temp = quest->head;
    int diff = 0;

    for (; temp; temp = temp->next) {
        if (temp->dialogue.is_talking)
            continue;
        diff = my_strcmp(npc->name, temp->name_npc);
        if (diff == 0 && temp->state == -1) {
            init_dialogue(npc, temp);
            return;
        }
        if (my_strcmp(npc->name, temp->name_npc) == 0) {
            temp->dialogue.is_talking = true;
            return;
        }
    }
}

static void verify_interract(npc_l *npc_lst, rpg_t *rpg)
{
    npc_lt *npc = npc_lst->head;

    for (; npc; npc = npc->next) {
        if (POS_PLAYER.x < POS_NPC.x + 75 && POS_PLAYER.x - 75 < POS_NPC.x &&
        rpg->input->interact.press)
            change_npc_dialogue_state(npc, rpg->quests);
        display_npc_dialogue(rpg->quests, rpg);
    }
}

void npc_interraction(rpg_t *rpg)
{
    if (rpg->npc && rpg->quests && rpg->quests->head && rpg->player) {
        if (rpg->npc->merchant)
            verify_interract(rpg->npc->merchant, rpg);
        if (rpg->npc->chef)
            verify_interract(rpg->npc->chef, rpg);
        if (rpg->npc->priest)
            verify_interract(rpg->npc->priest, rpg);
        if (rpg->npc->alchemist)
            verify_interract(rpg->npc->alchemist, rpg);
    }
}
