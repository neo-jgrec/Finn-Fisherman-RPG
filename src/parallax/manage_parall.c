/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_parall
*/

#include "rpg.h"

static int min_int(int i, int min)
{
    if (i < min)
        return min;
    return i;
}

static void manage_this_parall(entity_t *player,
    parall_t *parall, win_t *win, int i)
{
    int dist = 0;
    parall->pos[i].x += pow(parall->nb - i - 1, 2) *
        10 * player->hor * win->deltaT;
    dist = parall->pos[i].x - player->pos.x;
    if (dist < 0)
        dist = -dist;
    if (dist > parall->layers[i].size.x * 5)
        parall->pos[i].x = player->pos.x;
}

static void manage_this_parall_y(entity_t *player,
    parall_t *parall, int i)
{
    parall->pos[i].y = player->pos.y - 175;
    if (player->pos.y > parall->y_spawn)
        parall->pos[i].y = (player->pos.y - 175 + (i + 2) * 25 +
        min_int(parall->y_spawn - player->pos.y, -220));
    if (parall->pos[i].y < parall->y_spawn)
        parall->pos[i].y = parall->y_spawn;
}

void manage_parall(entity_t *player, parall_t *parall, win_t *win)
{
    if (parall->nb > 0) {
        parall->pos[0].x = player->pos.x;
        parall->pos[0].y = (player->pos.y - 175);
        if (player->pos.y > parall->y_spawn)
            parall->pos[0].y = (player->pos.y - 175 +
            min_int(parall->y_spawn - player->pos.y, -220));
    }
    for (int i = 1; i < parall->nb; i++) {
        if (player->hor != 0 &&
            (player->state == RUN ||
            player->state == ROLL || !player->grounded))
            manage_this_parall(player, parall, win, i);
        manage_this_parall_y(player, parall, i);
    }
}
