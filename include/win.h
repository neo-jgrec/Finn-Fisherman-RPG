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
        LOADING

    } scene_t;

    typedef struct win_s {
        sfEvent event;
        sfRenderWindow *win;
        sfClock *time;
        float deltaT;
        scene_t scene;
    } win_t;

    win_t *init_win(void);

#endif /* !WIN_H_ */
