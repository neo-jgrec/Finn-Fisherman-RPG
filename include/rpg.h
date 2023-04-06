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

    #define DELTAT(time) (SEC(sfClock_getElapsedTime(time).microseconds))
    #define SEC(time) ((float)(time) / 1000000)

    typedef struct win_t {
        sfEvent event;
        sfRenderWindow *win;
        sfClock *time;
        float deltaT;
    } win_t;

    typedef struct rpg_s {
        win_t *win;
    } rpg_t;

    int rpg(void);
    int main_loop(win_t *win, rpg_t *rpg);

    rpg_t *init_rpg(void);
    win_t *init_win(void);

#endif /* !_RPG_H__ */
