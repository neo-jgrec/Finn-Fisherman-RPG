/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** monster
*/

#ifndef MONSTER_H_
    #define MONSTER_H_

    #include "rpg.h"

void init_monster_1(rpg_t *rpg,
    entity_t *monster, sfVector2f pos);
void add_monster(rpg_t *rpg, id_t id, sfVector2f pos);
void draw_monsters(rpg_t *rpg);
void manage_monster(win_t *win, entity_t *monster, rpg_t *rpg);

#endif /* !MONSTER_H_ */
