/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parallax header
*/

#ifndef PARALLAX_H
    #define PARALLAX_H

    #include "rpg.h"

typedef struct parallax_system {
    char *name;
    char **layer_assets;
    sprite_t *layers_sprite;
    size_t *layers_speed;
    struct parallax_system *next;
    struct parallax_system *prev;
} parallax_t;

    void init_font_from_dir(rpg_t *rpg_data, char *dir_fp);
    void destroy_font(rpg_t *rpg_data);

#endif /* !PARALLAX_H */
