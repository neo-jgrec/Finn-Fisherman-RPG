/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** player_manager
*/

#include "rpg.h"

void player_input(window_t *win, player_t *player)
{
    if (win->event.type == sfEvtKeyPressed) {
        if (win->event.key.code == sfKeyQ && player->keyLeft == 0)
        player->keyLeft = 1;
    if (win->event.key.code == sfKeyD && player->keyRight == 0)
        player->keyRight = 1;
    }
    if (win->event.type == sfEvtKeyReleased) {
        if (win->event.key.code == sfKeyQ && player->keyLeft == 1)
            player->keyLeft = 0;
        if (win->event.key.code == sfKeyD && player->keyRight == 1)
            player->keyRight = 0;
    }
    player->dir.x = 0 + player->keyRight - player->keyLeft;
}

void player_manager(player_t *player, window_t *win)
{
    printf("%f %f\n", player->dir.x, win->deltaT);
    if (player->pos.y < 500)
        player->pos.y += 0.5 * win->deltaT * 200;
    player->pos.x += player->dir.x * win->deltaT * 200;
    player->rect.left = player->pos.x - player->rect.width;
    player->rect.top = player->pos.y - player->rect.height;
    sfRectangleShape_setPosition(player->sprite, player->pos);
}