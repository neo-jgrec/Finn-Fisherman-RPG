/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_player
*/

#include "rpg.h"

sfText *init_lvl_text(rpg_t *rpg)
{
    sfText *text = sfText_create();
    sfText_setFont(text, rpg->win->font);
    sfText_setCharacterSize(text, 16);
    sfText_setColor(text, sfBlack);
    return text;
}

static health_t init_charge(rpg_t *rpg)
{
    health_t health = {0};

    health.potion_hud = init_sprite("assets/player/hud/potion.png",
        (VEC){20, 4}, 1, 4);
    health.health_hud = init_sprite("assets/player/hud/health.png",
        (VEC){20, 4}, 1, 4);
    health.hud = init_sprite("assets/player/hud/hud.png",
        (VEC){33, 10}, 1, 4);
    health.xp_hud = init_sprite("assets/player/hud/xp.png",
        (VEC){33, 10}, 1, 4);
    health.health = 200;
    health.potion = 2;
    health.cd = 0;
    health.not_moving = 0;
    health.save_heal = 0;
    health.lvl_hud = init_lvl_text(rpg);
    health.damage_cd = 0;
    return health;
}

static void init_player_2(entity_t *player)
{
    player->hor = 0;
    player->grounded = 0;
    player->dir = 1;
    player->velocity = 0;
}

void init_player(asset_t *asset, rpg_t *rpg)
{
    entity_t *player = malloc(sizeof(entity_t));

    if (player == NULL)
        rpg->player = NULL;
    player->id = PLAYER;
    player->state = IDLE;
    player->prev_state = IDLE;
    player->pos = (VEC){500, 0};
    player->rect = (sfFloatRect){0, 0, 64, 64};
    player->time = 0;
    set_animation(player, asset->pa.idle, 1, NULL);
    player->jump = (jump_t){0, 0, 2, 2};
    player->roll = (roll_t){0, 1, 0, 0};
    player->attack = (attack_t){0, 0};
    player->health = init_charge(rpg);
    player->next = NULL;
    init_player_2(player);
    rpg->player = player;
    loading_screen(rpg, rpg->loading, 80, 0);
}
