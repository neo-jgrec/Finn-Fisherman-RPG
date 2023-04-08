/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_sprite
*/

#include "rpg.h"

sprite_t init_sprite(char *path,
    VEC size, int nb_frame, int scale)
{
    sprite_t sprite = {0};

    sprite.tx = sfTexture_createFromFile(path, NULL);
    sprite.sp = sfSprite_create();
    sfSprite_setScale(sprite.sp, (VEC){scale, scale});
    sfSprite_setOrigin(sprite.sp, (VEC){size.x / 2, size.y / 2});
    sfSprite_setTexture(sprite.sp, sprite.tx, sfTrue);
    sprite.size = size;
    sprite.nb_frame = nb_frame;
    return sprite;
}
