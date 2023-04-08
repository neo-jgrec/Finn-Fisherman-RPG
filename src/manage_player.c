/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_player
*/

#include "rpg.h"

static void set_position(win_t *win, player_t *player, rpg_t *rpg)
{
    move_player(player, (VEC){0, -1});
    check_collision(player, rpg->puzzle);
}

void manage_player(win_t *win, player_t *player, rpg_t *rpg)
{
    frame_t frame = player->frame;

    set_position(win, player, rpg);
    int time = (int)(DELTAT(player->time) / frame.cd) %
        frame.nb * frame.size;
    sfIntRect rect = (sfIntRect){time, 0, frame.size, frame.size};

    sfSprite_setPosition(player->sp, player->pos);
    sfSprite_setTextureRect(player->sp, rect);
}
