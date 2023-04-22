/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** asset
*/

#ifndef ASSET_H_
    #define ASSET_H_

    #include "rpg.h"

    typedef struct rpg_s rpg_t;

    typedef struct sprite_s {
        sfSprite *sp;
        sfTexture *tx;
        sfVector2f size;
        int nb_frame;
        float cd;
    } sprite_t;

    typedef struct player_anim_s {
        sprite_t run;
        sprite_t idle;
        sprite_t death;
        sprite_t attack_1;
        sprite_t attack_2;
        sprite_t damage;
        sprite_t jump_1;
        sprite_t jump_2;
        sprite_t roll;
        sprite_t healing;
        sprite_t fishing;
    } pa_t;

    typedef struct monster_anim_s {
        sprite_t run;
        sprite_t idle;
        sprite_t death;
        sprite_t attack_1;
        sprite_t attack_2;
        sprite_t attack_3;
        sprite_t shield;
        sprite_t damage;
    } ma_t;

    typedef struct asset_s {
        pa_t pa;
        ma_t ma_skeleton;
        ma_t ma_shroom;
        ma_t ma_eye;
        ma_t ma_ball;
        ma_t ma_troll;
        sprite_t tileset;
        sprite_t items;
    } asset_t;

    void init_asset(rpg_t *rpg);
    sprite_t init_sprite(char *path,
        sfVector2f size, int nb_frame, float scale);
    void free_sprite_t(sprite_t sprite);

#endif /* !ASSET_H_ */
