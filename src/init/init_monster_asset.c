/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_monster_asset
*/

#include "rpg.h"

static ma_t init_ma_skeleton(void)
{
    ma_t ma = {0};

    ma.attack_1 = init_sprite("assets/monsters/Skeleton/Attack.png",
        (VEC){150, 150}, 8, 2);
    ma.death = init_sprite("assets/monsters/Skeleton/Death.png",
        (VEC){150, 150}, 4, 2);
    ma.idle = init_sprite("assets/monsters/Skeleton/Idle.png",
        (VEC){150, 150}, 4, 2);
    ma.shield = init_sprite("assets/monsters/Skeleton/Shield.png",
        (VEC){150, 150}, 4, 2);
    ma.shield.cd = 0.8f;
    ma.damage = init_sprite("assets/monsters/Skeleton/Hit.png",
        (VEC){150, 150}, 4, 2);
    ma.run = init_sprite("assets/monsters/Skeleton/Walk.png",
        (VEC){150, 150}, 4, 2);
    return ma;
}

static ma_t init_ma_eye(void)
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
    return ma;
}

static ma_t init_ma_shroom(void)
{
    ma_t ma = {0};
    
    return ma;
}

void init_mas(asset_t *asset)
{
    asset->ma_eye = init_ma_eye();
    asset->ma_skeleton = init_ma_skeleton();
    asset->ma_shroom = init_ma_shroom();
}
