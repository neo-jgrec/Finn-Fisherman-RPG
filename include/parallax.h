/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parallax header
*/

#ifndef PARALLAX_H
    #define PARALLAX_H

typedef struct parallax_system {
    sfTexture *back_txt;
    sfSprite *back_spt;
} parallax_t;

    void init_parallax(rpg_t *rpg);

#endif /* !PARALLAX_H */
