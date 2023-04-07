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

    puzzle_t *init_puzzle(void);

#endif /* !PUZZLE_H_ */
