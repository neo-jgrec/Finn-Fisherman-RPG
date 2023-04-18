/*
** EPITECH PROJECT, 2023
** init_npc
** File description:
** init_npc
*/

#include "rpg.h"

void init_npc_sprites(npc_t *npc)
{
    init_merchant(npc->merchant, "Martin", (sfVector2f){500, 585});
}
