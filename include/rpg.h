/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg.h
*/

#ifndef _RPG_H__
    #define _RPG_H__
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <math.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>

    #include "win.h"
    #include "puzzle.h"
    #include "asset.h"
    #include "player.h"

    #define DELTAT(time) (SEC(sfClock_getElapsedTime(time).microseconds))
    #define SEC(time) ((float)(time) / 1000000)
    #define VEC sfVector2f
    #define UNUSED __attribute__((unused))

    typedef struct rpg_s {
        win_t *win;
        puzzle_t *puzzle;
        asset_t *asset;
        player_t *player;
    } rpg_t;

    int rpg(void);
    int main_loop(win_t *win, rpg_t *rpg);

    rpg_t *init_rpg(void);

#endif /* !_RPG_H__ */
