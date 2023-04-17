/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parallax header
*/

#ifndef PARALLAX_H
    #define PARALLAX_H

    #include <sys/types.h>

    #include "rpg.h"

    #define CAVE "assets/parallax/cave"

typedef struct parallax_system {
    char **layers_fp;
    size_t *layers_speed;
    sprite_t *layrs_sprites;
} parallax_t;

    // INIT PARALLAX

    void set_layer_fp(parallax_t *back, char *folder_fp);
    void set_layer_speed(parallax_t *back);
    void set_layer_sprites(parallax_t *back);

    void init_parallax(rpg_t *rpg, char *folder_fp);

    // DISPLAY

#endif /* !PARALLAX_H */
