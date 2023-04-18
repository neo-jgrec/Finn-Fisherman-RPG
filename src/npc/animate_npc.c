/*
** EPITECH PROJECT, 2023
** animate_npc
** File description:
** animate_npc
*/

#include "rpg.h"

static void main_anim(npc_lt *npc, win_t *win)
{
    npc->clock_anim_selec += win->deltaT;
    npc->anim.clock_anim += win->deltaT;

    if (npc->clock_anim_selec > 5) {
        NPC_RECT.top = 128;
        npc->anim.clock_anim = 0;
        NPC_RECT.left = 0;
        sfSprite_setTextureRect(NPC_SP, NPC_RECT);
        return;
    }
    if (npc->anim.clock_anim > 0.1) {
        NPC_RECT.left += 64;
        if (NPC_RECT.left == npc->anim.max_anim)
            NPC_RECT.left = 0;
        npc->anim.clock_anim = 0;
        sfSprite_setTextureRect(NPC_SP, NPC_RECT);
    }
}

static void sec_animation(npc_lt *npc, win_t *win)
{
    npc->clock_anim_selec += win->deltaT;
    npc->anim.clock_anim += win->deltaT;

    if (npc->sprite_info.pos_anim.left != npc->anim.max_sec_anim - 64) {
        if (npc->anim.clock_anim > 0.1) {
            NPC_RECT.left += 64;
            npc->anim.clock_anim = 0;
            sfSprite_setTextureRect(NPC_SP, NPC_RECT);
        }
    } else {
        NPC_RECT.top = 0;
        NPC_RECT.left = 0;
        npc->clock_anim_selec = 0;
        npc->anim.clock_anim = 0;
        sfSprite_setTextureRect(NPC_SP, NPC_RECT);
    }
}

static void anim_npc_lst(npc_l *npc_lst, win_t *win)
{
    npc_lt *temp = npc_lst->head;

    for (; temp; temp = temp->next){
        if (!temp->draw)
            continue;
        if (temp->clock_anim_selec > 5)
            sec_animation(temp, win);
        else
            main_anim(temp, win);
    }
}

void animate_npc(npc_t *npc, win_t *win)
{
    if (npc->alchemist->head)
        anim_npc_lst(npc->alchemist, win);
    if (npc->chef->head)
        anim_npc_lst(npc->chef, win);
    if (npc->merchant->head)
        anim_npc_lst(npc->merchant, win);
    if (npc->priest->head)
        anim_npc_lst(npc->priest, win);
}
