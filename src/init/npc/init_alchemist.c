/*
** EPITECH PROJECT, 2023
** init_alchemist
** File description:
** init_alchemist
*/

#include "rpg.h"

static void init_sprite_info(npc_lt *alchemist, sfVector2f pos)
{
    SP_ALCHEMIST = init_sprite("assets/npc/Alchemist.png",
    (sfVector2f){64, 64}, 1, 3.5);
    alchemist->sprite_info.pos_npc = pos;
    sfSprite_setPosition(SP_ALCHEMIST.sp, pos);
    alchemist->sprite_info.pos_anim = (sfIntRect){0, 0, 64,64};
}

static npc_lt *get_alchemist_info(char *name, sfVector2f pos,
npc_l *lst_alchemist)
{
    npc_lt *alchemist = malloc(sizeof(npc_lt));

    if (!alchemist)
        return (NULL);
    alchemist->name = my_strdup(name);
    init_sprite_info(alchemist, pos);
    alchemist->draw = false;
    alchemist->clock_anim_selec = 0;
    alchemist->anim.clock_anim = 0;
    alchemist->anim.max_sec_anim = 256;
    alchemist->anim.max_anim = 320;
    alchemist->next = NULL;
    alchemist->prev = lst_alchemist->tail;
    return (alchemist);
}

void init_alchemist(npc_l *lst_alchemist, char *name, sfVector2f pos,
rpg_t *rpg)
{
    npc_lt *alchemist = get_alchemist_info(name, pos, lst_alchemist);

    if (!alchemist)
        return;
    if (lst_alchemist->size == 0){
        lst_alchemist->head = alchemist;
        lst_alchemist->tail = alchemist;
    } else {
        lst_alchemist->tail->next = alchemist;
        lst_alchemist->tail = alchemist;
    }
    lst_alchemist->size++;
    add_quest_to_lst(rpg, name);
}
