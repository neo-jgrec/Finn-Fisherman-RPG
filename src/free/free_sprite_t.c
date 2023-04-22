/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** free_sprite_t
*/

#include "rpg.h"

void free_sprite_t(sprite_t sprite)
{
    sfSprite_destroy(sprite.sp);
    sfTexture_destroy(sprite.tx);
}
