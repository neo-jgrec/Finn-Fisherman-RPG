/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_player
*/

#include "rpg.h"

static charge_t init_charge(UNUSED rpg_t *rpg)
{
    charge_t charge = {0};

    charge.potion_hud = init_sprite("assets/player/hud/potion.png",
        (VEC){20, 4}, 1, 4);
    charge.health_hud = init_sprite("assets/player/hud/health.png",
        (VEC){20, 4}, 1, 4);
    charge.hud = init_sprite("assets/player/hud/hud.png",
        (VEC){33, 10}, 1, 4);
    charge.xp_hud = init_sprite("assets/player/hud/xp.png",
        (VEC){33, 10}, 1, 4);
    charge.health = 20;
    charge.potion = 1;
    charge.cd = 0;
    charge.not_moving = 0;
    return charge;
}

static void init_player_2(player_t *player)
{
    player->hor = 0;
    player->ver = 0;
    player->grounded = 0;
    player->dir = 1;
    player->velocity = 0;
}

void init_player(asset_t *asset, rpg_t *rpg)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        rpg->player = NULL;
    player->state = IDLE;
    player->prev_state = IDLE;
    player->pos = (VEC){500, 700};
    player->rect = (sfFloatRect){0, 0, 64, 64};
    player->time = 0;
    set_animation(player, asset->pa.idle, 1, NULL);
    player->jump = (jump_t){0, 0, 2, 2};
    player->roll = (roll_t){0, 1, 0, 0};
    player->charge = init_charge(rpg);
    init_player_2(player);
    rpg->player = player;
    loading_screen(rpg, rpg->loading, 80, 0);
}
