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
        int max_potion;
        int heal_power;
        int max_health;
        int speed;
        int damage;
        int crit_chance;
        int jump;
        int roll;
        int fishing;
        int attack;
        int lvl;
        int xp;
        int xp_to_lvl_up;
    } data_t;

    void init_data(rpg_t *rpg);

#endif /* !DATA_H_ */
