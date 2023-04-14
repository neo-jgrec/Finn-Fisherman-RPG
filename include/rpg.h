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
    #include <time.h>

    #include "mars.h"
    #include "xml_parser.h"
    #include "win.h"
    #include "puzzle.h"
    #include "asset.h"
    #include "entity.h"
    #include "player.h"
    #include "monster.h"
    #include "loading.h"
    #include "input.h"
    #include "data.h"
    #include "menu.h"
    #include "mars.h"

    #define SEC(time) ((float)(time) / 1000000)
    #define DELTAT(time) (SEC(sfClock_getElapsedTime(time).microseconds))
    #define VEC sfVector2f

    typedef struct rpg_s {
        win_t *win;
        puzzle_t *puzzle;
        data_t *data;
        asset_t *asset;
        entity_t *player;
        entity_t **monsters;
        loading_t *loading;
        input_t *input;
        menu_t *menu;
    } rpg_t;

    int rpg(void);

    int main_loop(win_t *win, rpg_t *rpg);
    void menu_loop(win_t *win, rpg_t *rpg);

    void scene_manager(rpg_t *rpg);

    void draw(win_t *win, rpg_t *rpg);

    rpg_t *init_rpg(void);

    int my_random(int min, int max);

#endif /* !_RPG_H__ */
