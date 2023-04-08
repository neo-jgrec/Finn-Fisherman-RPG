/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** puzzle
*/

#ifndef PUZZLE_H_
    #define PUZZLE_H_

    #include "rpg.h"

    typedef struct rpg_s rpg_t;
    typedef struct player_s player_t;

    typedef struct puzzle_s {
        sfFloatRect *colliders;
        int nb_colliders;
    } puzzle_t;

    void init_puzzle(rpg_t *rpg);

    void check_collision(player_t *player, puzzle_t *puzzle);

#endif /* !PUZZLE_H_ */
