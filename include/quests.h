/*
** EPITECH PROJECT, 2023
** quest
** File description:
** quest
*/

#ifndef QUESTS_
    #define QUESTS_

    #define Q_DESC (char*[]){quest->xml_npc, "Q_DESC", NULL\
    }
    #define DIALOGUE (char*[]){quest->xml_npc, "DIALOGUE", NULL\
    }
    #define DIALOGUE_FIN (char*[]){quest->xml_npc, "DIALOGUE_FINISH", NULL\
    }
    #define DIALOGUE_COMP (char*[]){quest->xml_npc, "DIALOGUE1", NULL\
    }
    #define REQ_NAME (char*[]){quest->xml_npc, "REQ_NAME", NULL\
    }
    #define REQ_OBJ (char*[]){quest->xml_npc, "REQUIREMENT_OBJ", NULL\
    }
    #define MAP (char*[]){quest->xml_npc, "MAP", NULL\
    }
    #define PARSER quest->dialogue.parser

    #include "rpg.h"

    typedef struct struct_requirement {
        char *requirement;
        int number_req;
        int number_get;
    } s_req;

    typedef struct s_dialogue {
        char **dialogue;
        char **dialogue_complete;
        char **dialogue_finish;
        bool is_talking;
        size_t parser;
        float clock_dialogue;
    } dialogue_t;

    typedef struct quest_struct {
        char *name_npc;
        char *xml_npc;
        char *q_desc;
        int state;
        int map;
        s_req requirement;
        dialogue_t dialogue;
        sfText *text;
        sfFont *font;
        struct quest_struct *next;
        struct quest_struct *prev;
    } quest_s;

    typedef struct quest_l {
        size_t size;
        quest_s *head;
        quest_s *tail;
    } quest_t;

    void my_strupcase(char **str);
    void get_xml_info_quest(quest_s *quest);
    void add_quest_to_lst(rpg_t *rpg, char *npc_name);
    void init_quest(rpg_t *rpg);
    void draw_text(rpg_t *rpg);
    void display_npc_dialogue(quest_t *quest, rpg_t *rpg);

#endif /* !QUESTS_ */
