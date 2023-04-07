/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_asset
*/

#include "rpg.h"

static sprite_t *init_sprite(char *path, int size, int nb_frame, int scale)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (sprite == NULL)
        return NULL;
    sprite->tx = sfTexture_createFromFile(path, NULL);
    sprite->sp = sfSprite_create();
    sfSprite_setScale(sprite->sp, (VEC){scale, scale});
    sfSprite_setOrigin(sprite->sp, (VEC){size / 2, size / 2});
    sfSprite_setTexture(sprite->sp, sprite->tx, sfTrue);
    sprite->size = size;
    sprite->nb_frame = nb_frame;
    return sprite;
}

asset_t *init_asset(void)
{
    asset_t *asset = malloc(sizeof(asset_t));

    if (asset == NULL)
        return NULL;
    asset->player = init_sprite("assets/player/run.png", 32, 6, 3);
    return asset;
}
