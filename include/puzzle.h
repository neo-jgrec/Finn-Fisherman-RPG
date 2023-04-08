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
    typedef struct sprite_s sprite_t;

    typedef struct puzzle_s {
        sfFloatRect *colliders;
        sprite_t *tileset;
        int nb_colliders;
        int **map;
    } puzzle_t;

    void init_puzzle(rpg_t *rpg);

    void check_collision(player_t *player, puzzle_t *puzzle, int axe);
    int on_ground(player_t *player, puzzle_t *puzzle);
    void draw_map(win_t *win, puzzle_t *puzzle);

#endif /* !PUZZLE_H_ */
