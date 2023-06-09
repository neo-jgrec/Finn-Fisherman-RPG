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
    typedef struct entity_s entity_t;

    typedef enum scene_e {

        NONE,
        GAME,
        MENU

    } scene_t;

    static const sfVector2u allowed_win_size[3] = {
        {1600, 900},
        {1920, 1080},
        {800, 450}
    };

    typedef struct win_s {
        sfEvent event;
        sfRenderWindow *win;
        sfClock *time;
        sfClock *warudo;
        float deltaT;
        sfImage *icon;
        scene_t scene;
        sfFont *font;
        sfVector2u size;
        int win_size;
        int win_style;
        int save_key;
    } win_t;

    void init_win(rpg_t *rpg);
    void cam_management(entity_t *player, win_t *win, rpg_t *rpg);
    void switch_size(win_t *win);
    void switch_style(win_t *win);

#endif /* !WIN_H_ */
