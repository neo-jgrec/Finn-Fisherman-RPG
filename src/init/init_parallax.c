/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_parallax
*/

#include <sys/types.h>
#include <dirent.h>
#include "rpg.h"

void init_parallax(rpg_t *rpg, char *folder_fp)
{
    rpg->font = malloc(sizeof(parallax_t));

    if (rpg->font == NULL)
        return;
    set_layer_fp(rpg->font, folder_fp);
    set_layer_speed(rpg->font);
    set_layer_sprites(rpg->font);
    return;
}
