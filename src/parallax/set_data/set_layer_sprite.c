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
    sfVector2u file;
    VEC origin;
    VEC position;

    for (size_t i = 0; i < NB_FILES; i++) {
        LAY_SPRITES[i].tx = sfTexture_createFromFile(FILEPATHS[i], NULL);
        file = sfTexture_getSize(LAY_SPRITES[i].tx);
        back->size = file;
        LAY_SPRITES[i].sp = sfSprite_create();
        back->scale = (VEC){WIN_X / file.x + 3, WIN_Y / file.y + 3};
        origin = (VEC){file.x / 2, file.y / 2 - 50};
        position = (VEC){player->pos.x, player->pos.y};
        sfSprite_setScale(LAY_SPRITES[i].sp, back->scale);
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
    back->is_moved = false;
    back->pos_x = player->pos.x;
    back->pos_y = player->pos.y;
    set_sprt_in_struct(rpg, player, back);
    return;
}
