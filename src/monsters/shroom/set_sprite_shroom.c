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
            set_animation(player, asset->ma_shroom.damage, 0, return_to_idle);
        else {
            rpg->data->xp += player->loot;
            add_info_text(rpg, sfGreen,
                (VEC){rpg->player->pos.x, rpg->player->pos.y - 50},
                    my_itoa(player->loot));
            set_animation(player, asset->ma_shroom.death, 0, death_anim);
        }
    }
}

static void new_anim(rpg_t *rpg,
    entity_t *player, asset_t *asset, p_state_e state)
{
    if (state == IDLE)
        set_animation(player, asset->ma_shroom.idle, 1, NULL);
    if (state == RUN)
        set_animation(player, asset->ma_shroom.run, 1, NULL);
    if (state == ATTACK)
        set_animation(player, asset->ma_shroom.attack_1, 0, attack_anim);
    new_anim_2(rpg, player, asset, state);
}

static void base_anim(entity_t *player)
{
    if (player->grounded == 1) {
        if (player->hor == 0)
            player->state = IDLE;
        else
            player->state = RUN;
    }
}

static void change_anim(entity_t *player, rpg_t *rpg)
{
    if (player->state != HIT &&
        player->state != ATTACK && player->state != SHIELD)
        base_anim(player);
    if (player->prev_state != player->state) {
        player->time = 0;
        new_anim(rpg, player, rpg->asset, player->state);
    }
    player->prev_state = player->state;
}

void set_sprite_shroom(entity_t *player, rpg_t *rpg)
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
