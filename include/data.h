/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** data
*/

#ifndef DATA_H_
    #define DATA_H_

    #include "rpg.h"

    typedef enum item_type_s {
        HELMET,
        ARMOR,
        PANT,
        BOOTS,
        RING_1,
        RING_2,
        NECKLACE
    } item_type_e;

    typedef enum item_id_s {
        EMPTY,
        BOOTS_1,
        BOOTS_2
    } item_id_e;

    typedef struct item_s {
        item_type_e type;
        item_id_e id;
        int equiped;
    } item_e;

    typedef struct player_stat_s {
        int max_potion;
        int heal_power;
        int max_health;
        int speed;
        int damage;
        int crit_chance;
    } player_stat_t;

    typedef struct data_s {
        player_stat_t player_stat;
        player_stat_t item_stat;
        int jump;
        int roll;
        int fishing;
        int attack;
        int lvl;
        int xp;
        int xp_to_lvl_up;
        int lvl_point;
        item_e *inventory;
    } data_t;

    void init_data(rpg_t *rpg);

#endif /* !DATA_H_ */
