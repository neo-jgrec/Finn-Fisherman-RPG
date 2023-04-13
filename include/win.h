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
    } win_t;

    void init_win(rpg_t *rpg);

#endif /* !WIN_H_ */
