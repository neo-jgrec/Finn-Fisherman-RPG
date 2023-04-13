/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** scene_manager
*/

#include "rpg.h"

void scene_manager(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->win->win)) {
        switch (rpg->win->scene) {
            case NONE:                                  break;
            case GAME: main_loop(rpg->win, rpg);        break;
            case MENU: menu_loop(rpg->win, rpg);        break;
            case LOADING: loading_loop(rpg->win, rpg);  break;
        }
    }
}
