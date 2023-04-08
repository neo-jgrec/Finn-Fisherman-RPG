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
    } sprite_t;

    typedef struct asset_s {
        sprite_t player;
        sprite_t tileset;
    } asset_t;

    void init_asset(rpg_t *rpg);
    sprite_t init_sprite(char *path,
        sfVector2f size, int nb_frame, int scale);

#endif /* !ASSET_H_ */
