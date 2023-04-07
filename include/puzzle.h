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

    typedef struct puzzle_s {
        sfFloatRect *colliders;
        int nb_colliders;
    } puzzle_t;

    void init_puzzle(rpg_t *rpg);

#endif /* !PUZZLE_H_ */
