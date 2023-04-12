/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** data
*/

#ifndef DATA_H_
    #define DATA_H_

    #include "rpg.h"

    typedef struct data_s {
        int nb_heal;
        int heal;
        int life;
        int speed;
        int damage;
        int crit_chance;
        int jump;
        int roll;
        int fishing;
        int attack;
    } data_t;

    void init_data(rpg_t *rpg);

#endif /* !DATA_H_ */
