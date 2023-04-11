/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_sprite
*/

#include "rpg.h"

static void new_anim(player_t *player, asset_t *asset, p_state_t state)
{
    if (state == IDLE)
        set_animation(player, asset->pa.idle, 1, NULL);
    if (state == RUN)
        set_animation(player, asset->pa.run, 1, NULL);
    if (state == ATTACK)
        set_animation(player, asset->pa.attack_1, 0, NULL);
    if (state == ROLL)
        set_animation(player, asset->pa.roll, 0, NULL);
    if (state == JUMP_1)
        set_animation(player, asset->pa.jump_1, 0, NULL);
    if (state == JUMP_2)
        set_animation(player, asset->pa.jump_2, 0, NULL);
}

static void base_anim(player_t *player, rpg_t *rpg, p_state_t prev)
{
    if (player->grounded == 1) {
        if (player->hor == 0)
            player->state = IDLE;
        else
            player->state = RUN;
    }
    if (player->grounded == 0) {
        if (player->jump.jump > 0)
            player->state = JUMP_1;
        else
            player->state = JUMP_2;
    }
}

static void change_anim(player_t *player, rpg_t *rpg)
{
    p_state_t prev = player->prev_state;

    if (prev == IDLE || prev == RUN || prev == JUMP_1 || prev == JUMP_2)
        base_anim(player, rpg, prev);
    if (player->prev_state != player->state) {
        sfClock_restart(player->time);
        new_anim(player, rpg->asset, player->state);
    }
    player->prev_state = player->state;
}

void set_sprite(player_t *player, rpg_t *rpg)
{
    frame_t frame = player->frame;
    VEC scale = sfSprite_getScale(player->sp);
    int time = 0;

    change_anim(player, rpg);
    time = (int)(DELTAT(player->time) / frame.cd);
    sfIntRect rect = (sfIntRect){time %
        frame.nb * frame.size, 0, frame.size, frame.size};
    if (frame.loop == 0 && time >= frame.nb)
        rect = (sfIntRect){(frame.nb - 1) *
            frame.size, 0, frame.size, frame.size};
    if (frame.loop == 0 && time > frame.nb && frame.action != NULL)
        frame.action(rpg);
    sfSprite_setPosition(player->sp, player->pos);
    sfSprite_setTextureRect(player->sp, rect);
    if (player->hor == 1)
        player->dir = 1;
    if (player->hor == -1)
        player->dir = -1;
    sfSprite_setScale(player->sp, (VEC){player->dir * fabs(scale.x), scale.y});
}
