/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_monster_asset
*/

#include "rpg.h"

static ma_t init_ma_ball(void)
{
    ma_t ma = {0};

    ma.attack_1 = init_sprite("assets/monsters/Eye/Attack.png",
        (VEC){150, 150}, 8, 3);
    ma.attack_1.cd = 0.07;
    ma.death = init_sprite("assets/monsters/Eye/Death.png",
        (VEC){150, 150}, 4, 3);
    ma.idle = init_sprite("assets/monsters/Eye/Idle.png",
        (VEC){150, 150}, 4, 3);
    ma.damage = init_sprite("assets/monsters/Eye/Hit.png",
        (VEC){150, 150}, 4, 3);
    ma.damage.cd = 0.05;
    return ma;
}

static ma_t init_ma_troll(void)
{
    ma_t ma = {0};

    ma.attack_1 = init_sprite("assets/monsters/troll/Attack.png",
        (VEC){200, 200}, 10, 5);
    ma.attack_1.cd = 0.06f;
    ma.death = init_sprite("assets/monsters/troll/Death.png",
        (VEC){200, 200}, 7, 5);
    ma.idle = init_sprite("assets/monsters/troll/Idle.png",
        (VEC){200, 200}, 10, 5);
    ma.damage = init_sprite("assets/monsters/troll/TakeHit.png",
        (VEC){200, 200}, 3, 5);
    ma.damage.cd = 0.05;
    ma.run = init_sprite("assets/monsters/troll/walk.png",
        (VEC){200, 200}, 8, 5);
    ma.attack_3 = init_sprite("assets/monsters/troll/Attack3.png",
        (VEC){200, 200}, 7, 5);
    ma.attack_2 = init_sprite("assets/monsters/troll/Attack2.png",
        (VEC){200, 200}, 9, 5);
    ma.attack_1.cd = 0.04f;
    return ma;
}

void init_mas_2(asset_t *asset)
{
    asset->ma_ball = init_ma_ball();
    asset->ma_troll = init_ma_troll();
}