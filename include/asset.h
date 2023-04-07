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
        int size;
        int nb_frame;
    } sprite_t;

    typedef struct asset_s {
        sprite_t *player;
    } asset_t;

    asset_t *init_asset(void);

#endif /* !ASSET_H_ */
