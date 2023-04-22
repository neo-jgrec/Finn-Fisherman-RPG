/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parallax header
*/

#ifndef PARALLAX_H
    #define PARALLAX_H

    #include "rpg.h"

typedef struct parall_s{
    sprite_t *layers;
    sfVector2f *pos;
    int nb;
    int y_spawn;
} parall_t;

    void draw_parall(win_t *win, parall_t *parall);
    void init_parall(entity_t *player, rpg_t *rpg);
    void manage_parall(entity_t *player, parall_t *parall, win_t *win);

#endif /* !PARALLAX_H */
