/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_spikes_collision
*/

#include "rpg.h"

void check_spikes_collision(rpg_t *rpg, entity_t *player, puzzle_t *puzzle)
{
    sfFloatRect rect = {0};
    int i = 0;

    for (; i < puzzle->nb_spikes; i++)
        if (sfFloatRect_intersects(&player->rect,
            &puzzle->spikes[i], &rect)) {
            hit_player(rpg, 10000, player);
            return;
        }
}
