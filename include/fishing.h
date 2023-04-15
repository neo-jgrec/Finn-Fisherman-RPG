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
        float clock_game;
        float clock_bar;
        float clock_keep;
        float clock_fish;
        int time_move_bar;
        int state_bar_moving;
        int res_fishing;
        bool bar_moving;
        bool state;
        sfVector2f game_pos;
        sfVector2f end_game_pos;
        sfVector2f start_game_pos;
        sfVector2f fish_pos;
        sfVector2f fish_zone_pos;
        sprite_t font;
        sprite_t fish;
        sfRectangleShape *fish_bar;
    } fishing_t;

    void init_fishing(rpg_t *rpg);

    void play_fishing_game(win_t *win, fishing_t *game, entity_t *player,
    rpg_t *rpg);
    void make_keep_zone_move(win_t *win, fishing_t *game);
    void make_fish_move(rpg_t *rpg, fishing_t *game);
    void end_game(fishing_t *game, win_t *win);

#endif /* !FISHING_ */
