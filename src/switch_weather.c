/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** switch_weather
*/

#include "rpg.h"

void switch_weather(rpg_t *rpg)
{
    rpg->weather = NONE_WEATHER;
    if (!(rpg->data->location % 2) && my_random(0, 3) == 1)
        rpg->weather = SNOW;
    if (rpg->data->location % 2 && my_random(0, 3) == 1)
        rpg->weather = RAIN;
}
