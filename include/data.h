/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** data
*/

#ifndef DATA_H_
    #define DATA_H_

    #include "rpg.h"

UNUSED static const char *data_default_xml = "\
<GAME>\n\
    <SAVENAME>9667854</SAVENAME>\n\
    <LOCATION>0</LOCATION>\n\
    <STARTED>0</STARTED><\n\
    <STATS>\n\
        <POTION>\n\
            <MAX_POTION>2</MAX_POTION>\n\
            <HEALTH_POWER>75</HEALTH_POWER>\n\
        </POTION>\n\
        <MAX_HEALTH>200</MAX_HEALTH>\n\
        <SPEED>400</SPEED>\n\
        <DAMAGE>50</DAMAGE>\n\
        <CRIT_CHANCE>30</CRIT_CHANCE>\n\
        <JUMP>1</JUMP>\n\
        <ROLL>1</ROLL>\n\
        <FISHING>1</FISHING>\n\
        <ATTACK>1</ATTACK>\n\
        <LEVEL>1</LEVEL>\n\
        <EXP>0</EXP>\n\
        <EXP_TO_NEXT_LEVEL>100</EXP_TO_NEXT_LEVEL>\n\
    </STATS>\n\
</GAME>\n\
";

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
        int location;
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
