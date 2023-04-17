/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_layer_sprites
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "rpg.h"

static void set_sprt_in_struct(rpg_t *rpg, entity_t *player, parallax_t *back)
{
    VEC file;
    VEC origin;
    VEC position;
    VEC scale;

    for (size_t i = 0; i < NB_FILES; i++) {
        file = (VEC){384, 216};
        LAY_SPRITES[i].tx = sfTexture_createFromFile(FILEPATHS[i], NULL);
        LAY_SPRITES[i].sp = sfSprite_create();
        scale = (VEC){WIN_X / file.x + 2, WIN_Y / file.y + 3};
        origin = (VEC){file.x / 2, file.y / 2 - 50};
        position = (VEC){player->pos.x, player->pos.y};
        sfSprite_setScale(LAY_SPRITES[i].sp, scale);
        sfSprite_setOrigin(LAY_SPRITES[i].sp, origin);
        sfSprite_setPosition(LAY_SPRITES[i].sp, position);
        sfSprite_setTexture(LAY_SPRITES[i].sp, LAY_SPRITES[i].tx, sfTrue);
        LAY_SPRITES[i].nb_frame = 60;
        LAY_SPRITES[i].cd = 0.1f;
    }
    return;
}

void set_layer_sprites(rpg_t *rpg, entity_t *player, parallax_t *back)
{
    if (FILEPATHS == NULL)
        return;
    LAY_SPRITES = malloc(sizeof(sprite_t) * NB_FILES);
    if (LAY_SPRITES == NULL)
        return;
    set_sprt_in_struct(rpg, player, back);
    return;
}
