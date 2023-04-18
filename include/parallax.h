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

    // DEFINES

    #define CAVE "./assets/parallax/cave"
    #define WIN_X rpg->win->size.x
    #define WIN_Y rpg->win->size.x
    #define FILEPATHS back->layers_fp
    #define NB_FILES back->nb_files
    #define LAY_SPRITES back->layrs_sprites
    #define VEC sfVector2f

    // STRUCT

typedef struct parallax_system {
    char **layers_fp;
    size_t nb_files;
    size_t *layers_speed;
    sprite_t *layrs_sprites;
    ssize_t pos_y;
    ssize_t pos_x;
    bool is_moved;
    sfVector2u size;
    sfVector2f scale;
} parallax_t;

    // INIT PARALLAX

    void set_layer_fp(parallax_t *back, char *folder_fp);
    void set_layer_speed(parallax_t *back);
    void set_layer_sprites(rpg_t *rpg, entity_t *player, parallax_t *back);

    void init_parallax(entity_t *player, rpg_t *rpg, char *folder_fp);

    // DISPLAY

    void draw_background(win_t *win, rpg_t *rpg);
    void draw_forground(win_t *win, rpg_t *rpg);

#endif /* !PARALLAX_H */
