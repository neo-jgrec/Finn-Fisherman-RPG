/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_anim
*/

#include "rpg.h"

void set_animation(player_t *player, sprite_t sp, int loop,
    void (*action)(rpg_t *))
{
    sfClock_restart(player->time);
    player->sp = sp.sp;
    player->frame = (frame_t){sp.size.x, sp.nb_frame, 0.1f, loop, action};
}
