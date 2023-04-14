/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** on_ground
*/

#include "rpg.h"

int on_ground(entity_t *player, puzzle_t *puzzle)
{
    sfFloatRect rect = {player->rect.left, player->rect.top + 64, 48, 1};

    for (int i = 0; i < puzzle->nb_colliders; i++)
        if (sfFloatRect_intersects(&rect, &puzzle->colliders[i], NULL))
            return 1;
    return 0;
}
