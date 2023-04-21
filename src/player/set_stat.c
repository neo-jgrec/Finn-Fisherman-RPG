/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_stat
*/

#include "rpg.h"

void add_stats(player_stat_t *dir, player_stat_t *add)
{
    dir->crit_chance += add->crit_chance;
    dir->damage += add->damage;
    dir->heal_power += add->heal_power;
    dir->jump += add->jump;
    dir->max_health += add->max_health;
    dir->max_potion += add->max_potion;
    dir->speed += add->speed;
}

void set_stat(rpg_t *rpg, UNUSED entity_t *player)
{
    rpg->data->tot_stat = (player_stat_t){0};
    add_stats(&rpg->data->tot_stat, &rpg->data->player_stat);
    for (int i = 0; i < 3 * 9; i++) {
        if (rpg->data->inventory[i] != NULL &&
            rpg->data->inventory[i]->equiped)
            add_stats(&rpg->data->tot_stat,
                &rpg->data->inventory[i]->item_stat);
    }
}
