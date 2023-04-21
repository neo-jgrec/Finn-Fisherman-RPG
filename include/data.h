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
    <STARTED>0</STARTED>\n\
    <STATS>\n\
        <POTION>\n\
            <MAX_POTION>2</MAX_POTION>\n\
            <HEALTH_POWER>75</HEALTH_POWER>\n\
        </POTION>\n\
        <MAX_HEALTH>200</MAX_HEALTH>\n\
        <SPEED>400</SPEED>\n\
        <DAMAGE>50</DAMAGE>\n\
        <CRIT_CHANCE>30</CRIT_CHANCE>\n\
        <JUMP>3</JUMP>\n\
        <LEVEL>1</LEVEL>\n\
        <EXP>0</EXP>\n\
        <EXP_TO_NEXT_LEVEL>100</EXP_TO_NEXT_LEVEL>\n\
        <LVL_POINT>0</LVL_POINT>\n\
    </STATS>\n\
    <EQUIPED></EQUIPED>\n\
    <INVENTORY></INVENTORY>\n\
</GAME>\n\
";

    typedef enum item_type_s {
        SWORD,
        HELMET,
        ARMOR,
        GANTS,
        BOOTS,
        RING,
        NECKLACE,
        POTION
    } item_type_e;

    typedef struct player_stat_s {
        int max_potion;
        int heal_power;
        int max_health;
        int speed;
        int damage;
        int crit_chance;
        int jump;
    } player_stat_t;

    typedef struct item_s {
        item_type_e type;
        player_stat_t item_stat;
        int sprite;
        int in_inventory;
        int equiped;
        char *desc;
        sfVector2f pos;
        struct item_s *next;
    } item_e;
    
    typedef struct data_s {
        xml_parser_t *parser;
        int location;
        player_stat_t tot_stat;
        player_stat_t player_stat;
        player_stat_t item_stat;
        int lvl;
        int xp;
        int xp_to_lvl_up;
        int lvl_point;
        item_e **inventory;
    } data_t;

    void init_data(rpg_t *rpg);

    void add_item(rpg_t *rpg, int nb, sfVector2f pos);
    void manage_items(rpg_t *rpg);
    void draw_items(rpg_t *rpg);
    void free_items(rpg_t *rpg);
    void init_inventory_equiped(data_t *data);

#endif /* !DATA_H_ */
