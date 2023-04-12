/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_data
*/

#include "rpg.h"

void init_data(rpg_t *rpg)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL)
        rpg->puzzle = NULL;
    data->max_potion = 2;
    data->heal_power = 75;
    data->max_health = 100;
    data->speed = 400;
    data->damage = 50;
    data->crit_chance = 50;
    data->jump = 6;
    data->roll = 1;
    data->fishing = 1;
    data->attack = 1;
    data->lvl = 14;
    data->xp = 20;
    data->xp_to_lvl_up = 100;
    rpg->data = data;
    loading_screen(rpg, rpg->loading, 45, 0);
}
