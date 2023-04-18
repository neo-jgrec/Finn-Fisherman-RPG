/*
** EPITECH PROJECT, 2023
** manage_npc
** File description:
** manage_npc
*/

#include "rpg.h"

void manage_npc(entity_t *player, win_t *win, npc_t *npc)
{
    if (!npc)
        return;
    verify_state_npc(player, npc);
    display_npc_lst(win, npc);
}
