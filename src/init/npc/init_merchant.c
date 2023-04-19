/*
** EPITECH PROJECT, 2023
** init_merchant
** File description:
** init_merchant
*/

#include "rpg.h"

static void init_sprite_info(npc_lt *merchant, sfVector2f pos)
{
    SP_MERCHANT = init_sprite("assets/npc/Merchant.png",
    (sfVector2f){64, 64}, 1, 3.5);
    merchant->sprite_info.pos_npc = pos;
    merchant->sprite_info.pos_anim = (sfIntRect){0, 0, 64,64};
    sfSprite_setTextureRect(SP_MERCHANT.sp, merchant->sprite_info.pos_anim);
    sfSprite_setPosition(SP_MERCHANT.sp, merchant->sprite_info.pos_npc);
}

static npc_lt *get_merchant_info(char *name, sfVector2f pos,
npc_l *lst_merchant)
{
    npc_lt *merchant = malloc(sizeof(npc_lt));

    if (!merchant)
        return (NULL);
    merchant->name = my_strdup(name);
    init_sprite_info(merchant, pos);
    merchant->draw = false;
    merchant->clock_anim_selec = 0;
    merchant->anim.clock_anim = 0;
    merchant->anim.max_sec_anim = 960;
    merchant->anim.max_anim = 320;
    merchant->next = NULL;
    merchant->prev = lst_merchant->tail;
    return (merchant);
}

void init_merchant(npc_l *lst_merchant, char *name, sfVector2f pos)
{
    npc_lt *merchant = get_merchant_info(name, pos, lst_merchant);

    if (!merchant)
        return;
    if (lst_merchant->size == 0){
        lst_merchant->head = merchant;
        lst_merchant->tail = merchant;
    } else {
        lst_merchant->tail->next = merchant;
        lst_merchant->tail = merchant;
    }
    lst_merchant->size++;
}
