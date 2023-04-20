/*
** EPITECH PROJECT, 2023
** fishing
** File description:
** fishing
*/

#ifndef FISHING_
    #define FISHING_

    #define sfLightGreen sfColor_fromRGB(197, 255, 0)
    #define sfYellow sfColor_fromRGB(255, 228, 0)
    #define sfOrange sfColor_fromRGB(255, 89, 0)
    #define FISHING_GAME !game || !game->info || !game->fish || \
!game->font || !game->zone

    #include <stdbool.h>
    #include "rpg.h"

    typedef struct fish_s {
        float speed_fish;
        float clock_fish;
        int time_move_fish;
        int direction_fish;
        bool fish_moving;
        sfVector2f pos_fish;
        sprite_t fish;
    } fish_t;

    typedef struct keep_zone_s {
        float speed_zone;
        float clock_zone;
        sfVector2f pos_zone;
        sfRectangleShape *zone;
    } zone_t;

    typedef struct font_s {
        sfVector2f pos_top;
        sfVector2f pos_bot;
        sfVector2f pos_font;
        sprite_t font;
    } font_t;

    typedef struct fish_info_s {
        bool game_state;
        float clock_game;
        float clock_keep_time;
        float game_start;
        int game_time;
        int res_fishing;
    } game_info_t;

    typedef struct fishing_s {
        fish_t *fish;
        zone_t *zone;
        font_t *font;
        game_info_t *info;
    } fishing_t;

    void init_fishing(rpg_t *rpg);

    void play_fishing_game(win_t *win, fishing_t *game, entity_t *player,
    rpg_t *rpg);
    void make_keep_zone_move(rpg_t *rpg, fishing_t *game);
    void make_fish_move(win_t *win, fishing_t *game);
    void change_zone_color(fishing_t *game);
    void end_game(fishing_t *game, win_t *win, rpg_t *rpg);

#endif /* !FISHING_ */
