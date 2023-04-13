/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** win
*/

#ifndef WIN_H_
    #define WIN_H_

    #include "rpg.h"

    typedef struct rpg_s rpg_t;
    typedef struct player_s player_t;

    typedef enum scene_e {

        NONE,
        GAME,
        LOADING,
        MENU

    } scene_t;

    typedef struct win_s {
        sfEvent event;
        sfRenderWindow *win;
        sfClock *time;
        float deltaT;
        scene_t scene;
        sfFont *font;
        sfVector2u size;
        int win_size;
        int win_style;
        int save_key;
    } win_t;

    void init_win(rpg_t *rpg);
    void cam_management(player_t *player, win_t *win, rpg_t *rpg);
    void switch_size(win_t *win);
    void switch_style(win_t *win);

#endif /* !WIN_H_ */
