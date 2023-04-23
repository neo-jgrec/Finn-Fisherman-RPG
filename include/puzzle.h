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
    typedef struct entity_s entity_t;
    typedef struct sprite_s sprite_t;

    UNUSED static char *map_list[7] = {
        "assets/map/map_0.xml",
        "assets/map/map_1.xml",
        "assets/map/map_2.xml",
        "assets/map/map_3.xml",
        "assets/map/map_4.xml",
        "assets/map/map_5.xml",
        "assets/map/map_6.xml"
    };

    typedef struct sign_s {
        sfFloatRect rect;
        int map;
    } sign_t;

    typedef struct puzzle_s {
        xml_parser_t *parser;
        sfFloatRect *colliders;
        sfFloatRect *spikes;
        sfFloatRect *fish_spot;
        sign_t *sign;
        sprite_t *tileset;
        int nb_colliders;
        int nb_spikes;
        int nb_fish_spot;
        int nb_sign;
        int **map;
        int **background;
        int **foreground;
        int **death;
        sfVector2f spawn;
    } puzzle_t;

    void init_puzzle(rpg_t *rpg);
    void free_puzzle(puzzle_t *puzzle);

    void check_collision(entity_t *player, puzzle_t *puzzle, int axe);
    int on_ground(entity_t *player, puzzle_t *puzzle);
    void draw_map(win_t *win, puzzle_t *puzzle, int **map);
    int init_map(puzzle_t *puzzle);
    int **map_parsing(const char *src);
    void init_fish_spot(puzzle_t *puzzle, xml_parser_t *parser);
    void init_sign(puzzle_t *puzzle, xml_parser_t *parser);

#endif /* !PUZZLE_H_ */
