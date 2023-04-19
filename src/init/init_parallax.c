/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_parallax
*/

#include <sys/types.h>
#include <dirent.h>
#include "rpg.h"

void init_parallax(entity_t *player, rpg_t *rpg, char *folder_fp)
{
    rpg->font = malloc(sizeof(parallax_t));
    rpg->font_cpy = malloc(sizeof(parallax_t));

    if (rpg->font == NULL)
        return;
    if (rpg->font_cpy == NULL)
        return;
    set_layer_fp(rpg->font, folder_fp);
    set_layer_fp(rpg->font_cpy, folder_fp);
    set_layer_speed(rpg->font);
    set_layer_speed(rpg->font_cpy);
    set_layer_sprites(rpg, player, rpg->font);
    set_layer_sprites(rpg, player, rpg->font_cpy);
    return;
}
