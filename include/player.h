/*
** EPITECH PROJECT, 2023
** player
** File description:
** player
*/

#ifndef _PLAYER_H__
    #define _PLAYER_H__

    #include "rpg.h"

    typedef struct stat_s {
        speed_t;
        gravity_t;
    } player_t;

    typedef struct player_s {
        sfFloatRect rect;
        sfVector2f pos;
        sfRectangleShape *sprite;
        int keyLeft;
        int keyRight;
        sfVector2f dir;
    } player_t;

    int player_controller(void);
    void player_manager(player_t *player, window_t *win);
    void player_input(window_t *win, player_t *player);

#endif /* !_PLAYER_H__ */
