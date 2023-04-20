/*
** EPITECH PROJECT, 2023
** get_xml_info_quest
** File description:
** get_xml_info_quest
*/

#include "rpg.h"

void get_xml_info_quest(quest_s *quest)
{
    xml_parser_t *parser = init_parser("assets/quest/quest.xml");
    parse_xml(parser);
    char *q_desc = get_value_by_tags(parser->root, Q_DESC);
    char *dialogue = get_value_by_tags(parser->root, DIALOGUE);
    char *dialogue_comp = get_value_by_tags(parser->root, DIALOGUE_COMP);
    char *dialogue_fin = get_value_by_tags(parser->root, DIALOGUE_FIN);
    char *requirement = get_value_by_tags(parser->root, REQ_NAME);
    char *nb_req = get_value_by_tags(parser->root, REQ_OBJ);

    if (!nb_req || !requirement || !dialogue || !q_desc)
        return;
    quest->dialogue.dialogue = my_strsplit(dialogue, "\n");
    quest->dialogue.dialogue_complete = my_strsplit(dialogue_comp, "\n");
    quest->dialogue.dialgue_finish = my_strsplit(dialogue_fin, "\n");
    quest->q_desc = my_strdup(q_desc);
    quest->requirement.number_req = my_atoi(nb_req);
    quest->requirement.requirement = my_strdup(requirement);
}
