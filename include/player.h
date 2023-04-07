/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** player
*/

#ifndef _PLAYER_H__
    #define _PLAYER_H__

    #include "rpg.h"

    typedef struct rpg_s rpg_t;

    typedef struct player_s {
        sfSprite *sp;
        sfFloatRect rect;
        sfVector2f pos;
        sfClock *time;
        int size;
        int nb_frame;
        float cd_frame;
    } player_t;

    void init_player(asset_t *asset, rpg_t *rpg);

    void manage_player(win_t *win, player_t *player, rpg_t *rpg);

#endif /* !_PLAYER_H__ */
