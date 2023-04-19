/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_fishing_spot
*/

#include "rpg.h"

void check_fishing_spot(rpg_t *rpg,
    entity_t *player, puzzle_t *puzzle)
{
    sfFloatRect rect = {0};
    int i = 0;

    if (player->state == FISHING)
        return;
    for (; i < puzzle->nb_fish_spot; i++)
        if (sfFloatRect_intersects(&player->rect,
            &puzzle->fish_spot[i], &rect)) {
            player->health.on_fish_spot = 1;
            return;
        }
    player->health.on_fish_spot = 0;
}
