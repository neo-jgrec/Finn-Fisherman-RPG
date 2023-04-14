/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** cam_management
*/

#include "rpg.h"

void cam_management(entity_t *player, win_t *win, UNUSED rpg_t *rpg)
{
    sfView *view = sfView_createFromRect(
        (sfFloatRect){player->pos.x - win->size.x / 2,
        player->pos.y - win->size.y / 2,
        win->size.x, win->size.y});
    sfRenderWindow_setView(win->win, view);
    sfView_destroy(view);
}
