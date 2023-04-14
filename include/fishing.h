/*
** EPITECH PROJECT, 2023
** fishing
** File description:
** fishing
*/

#ifndef FISHING_
    #define FISHING_

    #include <stdbool.h>
    #include "rpg.h"

    typedef struct fishing_s {
        float clock;
        bool state;
        sprite_t font;
        sprite_t fish;
        sfVector2f pos_fish;
        sfFloatRect rect_fish;
        sfRectangleShape *fish_bar;
    } fishing_t;

    void init_fishing(rpg_t *rpg);

    void play_fishing_game(win_t *win, fishing_t *game);

#endif /* !FISHING_ */
