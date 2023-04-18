/*
** EPITECH PROJECT, 2023
** verify_state_npc
** File description:
** verify_state_npc
*/

#include "rpg.h"

static bool npc_is_in_field(sfVector2f pos_npc, sfVector2f pos_player)
{
    if (pos_npc.x < pos_player.x + 1000 && pos_npc.x > pos_player.x - 1000)
        if (pos_npc.y < pos_player.y + 1000 && pos_npc.y > pos_player.y - 1000)
            return (true);
    return (false);
}

static void change_state_npc_lst(entity_t *player, npc_l *lst)
{
    npc_lt *temp = lst->head;

    for (; temp; temp = temp->next){
        if (npc_is_in_field(temp->sprite_info.pos_npc, player->pos))
            temp->draw = true;
        else
            temp->draw = false;
    }
}

void verify_state_npc(entity_t *player, npc_t *npc)
{
    if (npc->alchemist->head)
        change_state_npc_lst(player, npc->alchemist);
    if (npc->chef->head)
        change_state_npc_lst(player, npc->chef);
    if (npc->merchant->head)
        change_state_npc_lst(player, npc->merchant);
    if (npc->priest->head)
        change_state_npc_lst(player, npc->priest);
}
