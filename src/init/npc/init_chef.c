/*
** EPITECH PROJECT, 2023
** init_chef
** File description:
** init_chef
*/

#include "rpg.h"

static void init_sprite_info(npc_lt *chef, sfVector2f pos)
{
    SP_CHEF = init_sprite("assets/npc/Chef.png",
    (sfVector2f){64, 64}, 1, 3.5);
    chef->sprite_info.pos_npc = pos;
    sfSprite_setPosition(SP_CHEF.sp, pos);
    chef->sprite_info.pos_anim = (sfIntRect){0, 0, 64,64};
}

static npc_lt *get_chef_info(char *name, sfVector2f pos,
npc_l *lst_chef)
{
    npc_lt *chef = malloc(sizeof(npc_lt));

    if (!chef)
        return (NULL);
    chef->name = my_strdup(name);
    init_sprite_info(chef, pos);
    chef->draw = false;
    chef->clock_anim_selec = 0;
    chef->anim.clock_anim = 0;
    chef->anim.max_sec_anim = 1088;
    chef->anim.max_anim = 320;
    chef->next = NULL;
    chef->prev = lst_chef->tail;
    return (chef);
}

void init_chef(npc_l *lst_chef, char *name, sfVector2f pos)
{
    npc_lt *chef = get_chef_info(name, pos, lst_chef);

    if (!chef)
        return;
    if (lst_chef->size == 0){
        lst_chef->head = chef;
        lst_chef->tail = chef;
    } else {
        lst_chef->tail->next = chef;
        lst_chef->tail = chef;
    }
    lst_chef->size++;
}
