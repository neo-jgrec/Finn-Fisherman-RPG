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
    typedef struct window_s {
        sfEvent event;
        sfRenderWindow *window;
        sfClock *time;
        float deltaT;
    } window_t;

#endif /* !_RPG_H__ */
