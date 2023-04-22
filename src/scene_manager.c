/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** scene_manager
*/

#include "rpg.h"

void scene_manager(rpg_t *rpg)
{
    sfRenderWindow_setFramerateLimit(rpg->win->win, 60);
    while (sfRenderWindow_isOpen(rpg->win->win)) {
        switch (rpg->win->scene) {
            case NONE:  break;
            case GAME: main_loop(rpg->win, rpg);        break;
            case MENU: menu_loop(rpg->win, rpg);        break;
        }
    }
    if (rpg->save_path != NULL && rpg->data->parser != NULL) {
        save_data(rpg);
        save_xml(rpg->data->parser, rpg->save_path);
    }
    destroy_rpg(rpg);
}
