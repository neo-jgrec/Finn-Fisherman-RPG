/*
** EPITECH PROJECT, 2023
** display_npc
** File description:
** display_npc
*/

#include "rpg.h"

static void display_npc(win_t *win, npc_l *lst)
{
    npc_lt *temp = lst->head;

    for (; temp; temp = temp->next){
        if (temp->draw)
            sfRenderWindow_drawSprite(win->win,
            temp->sprite_info.sprite_npc.sp, NULL);
    }
}

void display_npc_lst(win_t *win, npc_t *npc)
{
    if (npc->alchemist->head)
        display_npc(win, npc->alchemist);
    if (npc->chef->head)
        display_npc(win, npc->chef);
    if (npc->merchant->head)
        display_npc(win, npc->merchant);
    if (npc->priest->head)
        display_npc(win, npc->priest);
}
