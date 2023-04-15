/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_monster
*/

#include "rpg.h"

static void set_var(entity_t *monster, rpg_t *rpg)
{
    monster->time += rpg->win->deltaT;
    monster->hor = 0;
    monster->grounded = on_ground(monster, rpg->puzzle);
    if (monster->grounded) {
        monster->jump.nb = rpg->data->jump;
        if (monster->velocity > 0)
            monster->velocity = 0;
    }
}

void manage_monster(win_t *win, entity_t *monster, rpg_t *rpg)
{
    set_var(monster, rpg);
    set_position(win, monster, rpg);
}
