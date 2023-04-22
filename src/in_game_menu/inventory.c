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

static void equip_inv(rpg_t *rpg, size_t i)
{
    for (size_t j = 0; (3 * 7) > j; j++) {
        if (rpg->data->inventory[j] != NULL && rpg->data->inventory[j]->equiped
        && rpg->data->inventory[j]->type == rpg->data->inventory[i]->type) {
            rpg->data->inventory[j]->equiped = false;
            rpg->data->inventory[i]->equiped = true;
        }
    }
}

static void display_description(rpg_t *rpg, size_t i)
{
    sfText *text = sfText_create();
    sfVector2f text_pos = {sfRenderWindow_getSize(
        rpg->win->win).x - sfRenderWindow_getSize(rpg->win->win).x / 3,
        sfRenderWindow_getSize(rpg->win->win).y / 2};

    sfSprite_setColor(rpg->asset->items.sp, (sfColor){255, 255, 255, 255});
    sfSprite_setPosition(rpg->asset->items.sp, (sfVector2f)
        {text_pos.x - 32 + 16, text_pos.y - 32 - 16});
    sfRenderWindow_drawSprite(rpg->win->win, rpg->asset->items.sp, NULL);
    sfText_setPosition(text, text_pos);
    sfText_setString(text, rpg->data->inventory[i]->desc);
    sfText_setFont(text, rpg->menu->font);
    sfText_setCharacterSize(text, 16);
    sfRenderWindow_drawText(rpg->win->win, text, NULL);
    sfText_destroy(text);
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
        display_description(rpg, i);
        if (!rpg->data->inventory[i]->equiped)
            sfSprite_setColor(rpg->asset->items.sp, sfWhite);
        else
            sfSprite_setColor(rpg->asset->items.sp, (sfColor){0, 255, 0, 255});
        if (sfKeyboard_isKeyPressed(sfKeyR))
            rpg->data->inventory[i] = NULL;
        if (sfKeyboard_isKeyPressed(sfKeyE))
            equip_inv(rpg, i);
    }
}

void draw_inventory(rpg_t *rpg)
{
    sfIntRect texture_rect;
    sfVector2f pos;

    event_manager(rpg);
    for (size_t i = 0; (3 * 7) > i; i++) {
        if (!rpg->data->inventory[i]) continue;
        pos = (sfVector2f){((i % 8) * 64 + 300), ((i / 8) * 64 + 300)};
        texture_rect = (sfIntRect){(rpg->data->inventory[i]->sprite % 8) * 16,
            (rpg->data->inventory[i]->sprite / 8) * 16, 16, 16};
        handle_actions(rpg, pos, i);
        sfSprite_setTextureRect(rpg->asset->items.sp, texture_rect);
        sfSprite_setPosition(rpg->asset->items.sp, pos);
        sfSprite_setScale(rpg->asset->items.sp, (VEC){4, 4});
        sfRenderWindow_drawSprite(rpg->win->win, rpg->asset->items.sp, NULL);
    }
    sfSprite_setColor(rpg->asset->items.sp, sfWhite);
}
