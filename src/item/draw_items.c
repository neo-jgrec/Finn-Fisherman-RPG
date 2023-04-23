/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_items
*/

#include "rpg.h"

static void draw_item(rpg_t *rpg, item_e *item)
{
    sfIntRect rect = {0};

    printf("%d\n", item->sprite);
    rect = (sfIntRect){(item->sprite % 8) * 16,
            (item->sprite / 8) * 16, 16, 16};
    sfSprite_setTextureRect(rpg->asset->items.sp, rect);
    sfSprite_setPosition(rpg->asset->items.sp, item->pos);
    sfSprite_setScale(rpg->asset->items.sp, (VEC){2, 2});
    sfRenderWindow_drawSprite(rpg->win->win, rpg->asset->items.sp, NULL);
}

void draw_items(rpg_t *rpg)
{
    item_e **items = rpg->items;

    for (item_e *node = *items; node; node = node->next)
        draw_item(rpg, node);
}
