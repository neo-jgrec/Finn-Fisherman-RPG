/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#include "rpg.h"

static void event_manager(rpg_t *rpg)
{
    if (rpg->win->event.type == sfEvtKeyPressed) {
        if (rpg->win->event.key.code == sfKeyEscape)
            rpg->menu->in_game_menu->panel_type = NONE_PANEL;
    }
    sfRenderWindow_setView(rpg->win->win,
        sfRenderWindow_getDefaultView(rpg->win->win));
}

static void handle_actions(rpg_t *rpg, sfVector2f pos, size_t i)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->win->win);

    if (!sfFloatRect_contains(&(sfFloatRect){pos.x - 32, pos.y - 32, 64,
        64}, mouse_pos.x, mouse_pos.y)) {
        if (!rpg->data->inventory[i]->equiped)
            sfSprite_setColor(rpg->asset->items.sp,
                (sfColor){255, 255, 255, 128});
        else
            sfSprite_setColor(rpg->asset->items.sp, (sfColor){0, 255, 0, 128});
    } else {
        if (!rpg->data->inventory[i]->equiped)
            sfSprite_setColor(rpg->asset->items.sp, sfWhite);
        else
            sfSprite_setColor(rpg->asset->items.sp, (sfColor){0, 255, 0, 255});
        if (sfKeyboard_isKeyPressed(sfKeyR))
            rpg->data->inventory[i] = NULL;
        if (sfKeyboard_isKeyPressed(sfKeyE))
            rpg->data->inventory[i]
                ->equiped = !rpg->data->inventory[i]->equiped;
    }
}

void draw_inventory(rpg_t *rpg)
{
    sfIntRect texture_rect;
    sfVector2f pos;

    event_manager(rpg);
    for (size_t i = 0; (3 * 8) > i; i++) {
        if (!rpg->data->inventory[i]) continue;
        pos = (sfVector2f){((i % 8) * 64 + 300), ((i / 8) * 64 + 300)};
        texture_rect = (sfIntRect){(rpg->data->inventory[i]->sprite % 8) * 16,
            (rpg->data->inventory[i]->sprite / 8) * 16, 16, 16};
        sfSprite_setTextureRect(rpg->asset->items.sp, texture_rect);
        sfSprite_setPosition(rpg->asset->items.sp, pos);
        sfSprite_setScale(rpg->asset->items.sp, (VEC){4, 4});
        handle_actions(rpg, pos, i);
        sfRenderWindow_drawSprite(rpg->win->win, rpg->asset->items.sp, NULL);
    }
}
