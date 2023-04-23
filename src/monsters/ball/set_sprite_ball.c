/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_sprite_skeleton
*/

#include "rpg.h"

void set_sprite_ball(entity_t *player, rpg_t *rpg)
{
    frame_t frame = player->frame;
    int time = 0;
    sfIntRect rect = {0};

    time = (int)(player->time / frame.cd);
    rect = (sfIntRect){time %
        frame.nb * frame.size, 0, frame.size, frame.size};
    if (frame.loop == 0 && time >= frame.nb)
        rect = (sfIntRect){(frame.nb - 1) *
            frame.size, 0, frame.size, frame.size};
    if (frame.loop == 0 && time > frame.nb && frame.action != NULL)
        frame.action(rpg, player);
    sfSprite_setPosition(player->sp, player->pos);
    sfSprite_setTextureRect(player->sp, rect);
    if (!(player->health.health <= 0))
        flip(player);
}
