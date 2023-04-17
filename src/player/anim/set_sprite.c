/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_sprite
*/

#include "rpg.h"

static void new_anim_2(entity_t *player, asset_t *asset, p_state_e state)
{
    if (state == HEALING)
        set_animation(player, asset->pa.healing, 0, heal_anim);
    if (state == HIT) {
        if (player->health.health)
            set_animation(player, asset->pa.damage, 0, return_to_idle);
        else
            set_animation(player, asset->pa.death, 0, death_anim);
    }
    if (state == ATTACK) {
        if (player->attack.crit)
            set_animation(player, asset->pa.attack_2, 0, attack_anim);
        else
            set_animation(player, asset->pa.attack_1, 0, attack_anim);
    }
}

static void new_anim(entity_t *player, asset_t *asset, p_state_e state)
{
    if (state == IDLE)
        set_animation(player, asset->pa.idle, 1, NULL);
    if (state == RUN)
        set_animation(player, asset->pa.run, 1, NULL);
    if (state == ATTACK)
        set_animation(player, asset->pa.attack_1, 0, NULL);
    if (state == ROLL)
        set_animation(player, asset->pa.roll, 0, return_to_idle);
    if (state == JUMP_1)
        set_animation(player, asset->pa.jump_1, 0, NULL);
    if (state == JUMP_2)
        set_animation(player, asset->pa.jump_2, 0, NULL);
    new_anim_2(player, asset, state);
}

static void base_anim(entity_t *player)
{
    if (player->grounded == 1) {
        if (player->hor == 0)
            player->state = IDLE;
        else
            player->state = RUN;
    }
    if (player->grounded == 0) {
        if (player->velocity < 0)
            player->state = JUMP_1;
        else
            player->state = JUMP_2;
    }
}

static void change_anim(entity_t *player, rpg_t *rpg)
{
    if (player->state != ROLL && player->state != HEALING &&
        player->state != HIT && player->state != ATTACK)
        base_anim(player);
    if (player->prev_state != player->state) {
        player->time = 0;
        new_anim(player, rpg->asset, player->state);
    }
    player->prev_state = player->state;
}

void set_sprite(entity_t *player, rpg_t *rpg)
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
        flip(player, rpg);
}
