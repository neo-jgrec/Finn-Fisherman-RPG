/*
** EPITECH PROJECT, 2023
** init_priest
** File description:
** init_priest
*/

#include "rpg.h"

static void init_sprite_info(npc_lt *priest, sfVector2f pos)
{
    SP_PRIEST = init_sprite("assets/npc/Priest.png",
    (sfVector2f){64, 64}, 1, 3.5);
    priest->sprite_info.pos_npc = pos;
    sfSprite_setPosition(SP_PRIEST.sp, pos);
    priest->sprite_info.pos_anim = (sfIntRect){0, 0, 64,64};
}

static npc_lt *get_priest_info(char *name, sfVector2f pos,
npc_l *lst_priest)
{
    npc_lt *priest = malloc(sizeof(npc_lt));

    if (!priest)
        return (NULL);
    priest->name = my_strdup(name);
    init_sprite_info(priest, pos);
    priest->draw = false;
    priest->clock_anim_selec = 0;
    priest->anim.clock_anim = 0;
    priest->anim.max_sec_anim = 1216;
    priest->anim.max_anim = 320;
    priest->next = NULL;
    priest->prev = lst_priest->tail;
    return (priest);
}

void init_priest(npc_l *lst_priest, char *name, sfVector2f pos, rpg_t *rpg)
{
    npc_lt *priest = get_priest_info(name, pos, lst_priest);

    if (!priest)
        return;
    if (lst_priest->size == 0){
        lst_priest->head = priest;
        lst_priest->tail = priest;
    } else {
        lst_priest->tail->next = priest;
        lst_priest->tail = priest;
    }
    lst_priest->size++;
    add_quest_to_lst(rpg, name);
}
