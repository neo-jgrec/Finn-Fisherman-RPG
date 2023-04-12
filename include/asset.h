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
        sprite_t damage;
        sprite_t jump_1;
        sprite_t jump_2;
        sprite_t roll;
        sprite_t healing;
    } pa_t;

    typedef struct asset_s {
        pa_t pa;
        sprite_t tileset;
    } asset_t;

    void init_asset(rpg_t *rpg);
    sprite_t init_sprite(char *path,
        sfVector2f size, int nb_frame, int scale);

#endif /* !ASSET_H_ */
