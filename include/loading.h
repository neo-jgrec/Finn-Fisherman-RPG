/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** loading
*/

#ifndef LOADING_H_
    #define LOADING_H_

    #include "rpg.h"

    typedef struct rpg_s rpg_t;

    typedef struct loading_s {
        sprite_t **fishs;
        int nb_fish;
        int fish;
    } loading_t;

    void loading_screen(rpg_t *rpg, loading_t *loading,
        int pourcentage, int next);

    void init_loading(rpg_t *rpg);

#endif /* !LOADING_H_ */
