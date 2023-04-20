/*
** EPITECH PROJECT, 2023
** manage_npc
** File description:
** manage_npc
*/

#include "rpg.h"

void manage_npc(rpg_t *rpg, npc_t *npc)
{
    if (!npc)
        return;
    verify_state_npc(rpg->player, npc);
    npc_interraction(rpg);
    animate_npc(npc, rpg->win);
}
