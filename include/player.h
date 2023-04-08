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

    typedef struct frame_s {
        int size;
        int nb;
        float cd;
    } frame_t;

    typedef struct stat_s {
        int speed;
    } stat_t;

    typedef struct jump_s {
        float jump;
        int save;
        float press_time;
        float ground_time;
    } jump_t;

    typedef struct player_s {
        sfSprite *sp;
        sfFloatRect rect;
        sfVector2f pos;
        sfClock *time;
        frame_t frame;
        jump_t jump;
        int hor;
        int ver;
        int grounded;
    } player_t;

    void init_player(asset_t *asset, rpg_t *rpg);

    void manage_player(win_t *win, player_t *player, rpg_t *rpg);
    void move_player(player_t *player, sfVector2f dir);
    void manage_jump(player_t *player, rpg_t *rpg);

#endif /* !_PLAYER_H__ */
