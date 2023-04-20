/*
** EPITECH PROJECT, 2023
** npc_interraction
** File description:
** npc_interraction
*/

#include "rpg.h"

static void display_npc_dialogue(char *npc_name, quest_t *quest)
{
    quest_s *temp = quest->head;

    for (; temp; temp = temp->next)
        if (my_strcmp(npc_name, temp->name_npc) == 0)
            return;
}

static void verify_interract(npc_l *npc_lst, rpg_t *rpg)
{
    npc_lt *npc = npc_lst->head;

    for (; npc; npc = npc->next) {
        if (POS_PLAYER.x < POS_NPC.x + 75 && POS_PLAYER.x - 75 < POS_NPC.x &&
        rpg->input->interact.press)
            display_npc_dialogue(npc->name, rpg->quests);
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
