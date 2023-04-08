/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_collision
*/

#include "rpg.h"

void check_collision(player_t *player, puzzle_t *puzzle, int axe)
{
    sfFloatRect rect = {0};
    int i = 0;

    for (; i < puzzle->nb_colliders; i++)
        if (sfFloatRect_intersects(&player->rect, &puzzle->colliders[i], &rect))
            break;
    if (player->pos.y < puzzle->colliders[i].top)
        rect.height = -rect.height;
    if (player->pos.x < puzzle->colliders[i].left)
        rect.width = -rect.width;
    if (axe == 0)
        rect.width = 0;
    else
        rect.height = 0;
    move_player(player, (VEC){rect.width, rect.height});
}
