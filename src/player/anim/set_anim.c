/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_anim
*/

#include "rpg.h"

void set_animation(entity_t *player, sprite_t sp, int loop,
    void (*action)(rpg_t *))
{
    player->sp = sp.sp;
    player->frame = (frame_t){sp.size.x, sp.nb_frame, sp.cd, loop, action};
}
