/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_sprite_skeleton
*/

#include "rpg.h"

static void new_anim_2(rpg_t *rpg,
    entity_t *player, asset_t *asset, p_state_e state)
{
    if (state == HIT) {
        if (player->health.health)
            set_animation(player, asset->ma_eye.damage, 0, return_to_idle);
        else {
            rpg->data->xp += player->loot;
            set_animation(player, asset->ma_eye.death, 0, death_anim);
        }
    }
    if (state == ATTACK) {
        if (player->attack.crit)
            set_animation(player, asset->ma_eye.attack_1, 0, attack_anim);
        else
            set_animation(player, asset->ma_eye.attack_1, 0, attack_anim);
    }
}

static void new_anim(rpg_t *rpg,
    entity_t *player, asset_t *asset, p_state_e state)
{
    if (state == IDLE)
        set_animation(player, asset->ma_eye.idle, 1, NULL);
    if (state == ATTACK)
        set_animation(player, asset->ma_eye.attack_1, 0, NULL);
    new_anim_2(rpg, player, asset, state);
}

static void change_anim(entity_t *player, rpg_t *rpg)
{
    if (player->state != ROLL && player->state != HEALING &&
        player->state != HIT && player->state != ATTACK)
        player->state = IDLE;
    if (player->prev_state != player->state) {
        player->time = 0;
        new_anim(rpg, player, rpg->asset, player->state);
    }
    player->prev_state = player->state;
}

void set_sprite_eye(entity_t *player, rpg_t *rpg)
{
    frame_t frame = player->frame;
    int time = 0;
    sfIntRect rect = {0};

    change_anim(player, rpg);
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
