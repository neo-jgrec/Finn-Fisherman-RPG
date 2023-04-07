/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_player
*/

#include "rpg.h"

void manage_player(win_t *win, player_t *player, rpg_t *rpg)
{
    int time = (int)(DELTAT(player->time) / player->cd_frame) %
        player->nb_frame * player->size;
    sfIntRect rect = (sfIntRect){time, 0, player->size, player->size};

    sfSprite_setPosition(player->sp, player->pos);
    sfSprite_setTextureRect(player->sp, rect);
}
