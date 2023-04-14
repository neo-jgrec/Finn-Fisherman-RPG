/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** monster
*/

#ifndef MONSTER_H_
    #define MONSTER_H_

    #include "rpg.h"

void init_monster_1(rpg_t *rpg_t,
    asset_t *asset, entity_t *monster, sfVector2f pos);
void add_monster(rpg_t *rpg, entity_t **monsters, id_t id, sfVector2f pos);

#endif /* !MONSTER_H_ */
