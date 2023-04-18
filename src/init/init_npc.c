/*
** EPITECH PROJECT, 2023
** init_npc
** File description:
** init_npc
*/

#include "rpg.h"

static npc_l *init_npc_lst(void)
{
    npc_l *lst = malloc(sizeof(npc_l));

    if (!lst)
        return (NULL);
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
    return (lst);
}

static void destroy_npc_struct(npc_t *npc)
{
    if (npc->alchemist)
        free(npc->alchemist);
    if (npc->chef)
        free(npc->chef);
    if (npc->merchant)
        free(npc->merchant);
    if (npc->priest)
        free(npc->priest);
    free(npc);
}

static npc_t *init_npc_struct(void)
{
    npc_t *npc = malloc(sizeof(npc_t));

    if (!npc)
        return (NULL);
    npc->alchemist = init_npc_lst();
    npc->chef = init_npc_lst();
    npc->merchant = init_npc_lst();
    npc->priest = init_npc_lst();
    if (!npc->alchemist || !npc->chef || !npc->merchant || !npc->priest){
        destroy_npc_struct(npc);
        return (NULL);
    }
    return (npc);
}

void init_npc(rpg_t *rpg)
{
    npc_t *npc = init_npc_struct();

    rpg->npc = NULL;
    if (!npc)
        return;
    init_npc_sprites(npc);
    rpg->npc = npc;
}
