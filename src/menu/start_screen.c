/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** start_screen
*/

#include "rpg.h"

static void event_manager(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->win->win, &rpg->win->event)) {
        if (rpg->win->event.type == sfEvtClosed) {
            rpg->win->scene = NONE;
            sfRenderWindow_close(rpg->win->win);
        }
    }
}

static void loop(rpg_t *rpg)
{
    sfText *text = sfText_create();

    sfText_setFont(text, rpg->menu->font);
    sfText_setString(text, "Press space to continue");
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(rpg->win->win)) {
        event_manager(rpg);
        if (sfKeyboard_isKeyPressed(sfKeySpace)) break;
        sfRenderWindow_clear(rpg->win->win, sfBlack);
        sfRectangleShape_setSize(rpg->menu->how_to_play,
            (sfVector2f){rpg->win->size.x, rpg->win->size.y});
        sfRenderWindow_drawRectangleShape(rpg->win->win,
            rpg->menu->how_to_play, NULL);
        sfRenderWindow_drawText(rpg->win->win, text, NULL);
        sfRenderWindow_display(rpg->win->win);
    }
    sfText_destroy(text);
}

void start_screen(rpg_t *rpg)
{
    if (rpg->menu->saves[rpg->menu->save_reference]->is_write == 0) {
        rpg->menu->saves[rpg->menu->save_reference]->is_write = 1;
        sfRenderWindow_clear(rpg->win->win, sfBlack);
        sfRectangleShape_setSize(rpg->menu->lore,
            (sfVector2f){rpg->win->size.x, rpg->win->size.y});
        sfRenderWindow_drawRectangleShape(rpg->win->win,
            rpg->menu->lore, NULL);
        sfRenderWindow_display(rpg->win->win);
        sfSleep((sfTime){1000000});
        loop(rpg);
    }
}
