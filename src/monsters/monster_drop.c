/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** monster_drop
*/

#include "rpg.h"

static int get_item_drop(char *drop_list)
{
    int ret = 0;
    int len = 0;
    char **stw = a_mkstw(drop_list, "-");

    if (stw == NULL)
        return 0;
    for (; stw[len]; len++);
    ret = my_atoi(stw[my_random(0, len - 1)]);
    a_freestw(stw);
    return ret;
}

void monster_drop(rpg_t *rpg, entity_t *entity)
{
    add_info_text(rpg, sfGreen,
                (VEC){rpg->player->pos.x, rpg->player->pos.y - 50},
                    my_itoa(entity->loot));
    if (entity->drop_list == NULL)
        return;
    add_item(rpg, get_item_drop(entity->drop_list),
    (VEC){entity->pos.x + my_random(0, 100) - 50,
        entity->pos.y - 50});
}