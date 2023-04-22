/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_if_consomable
*/

#include "rpg.h"

static void check_limit(entity_t *player, data_t *data)
{
    if (player->health.potion > data->tot_stat.max_potion)
        player->health.potion = data->tot_stat.max_potion;
    if (player->health.health > data->tot_stat.max_health)
        player->health.health = data->tot_stat.max_health;
}

void check_consomable(rpg_t *rpg)
{
    data_t *data = rpg->data;

    for (int i = 0; i < 9 * 3; i++) {
        if (data->inventory[i] != NULL &&
            data->inventory[i]->type == FISH &&
                data->inventory[i]->equiped) {
            play_sound(HEAL_SOUND, rpg);
            rpg->player->health.health +=
                data->inventory[i]->item_stat.max_health;
            rpg->player->health.potion +=
                data->inventory[i]->item_stat.max_potion;
            free(rpg->data->inventory[i]);
            rpg->data->inventory[i] = NULL;
            check_limit(rpg->player, data);
        }
    }
}
