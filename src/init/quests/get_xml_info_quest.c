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
    char *requirement = get_value_by_tags(parser->root, REQ_NAME);
    char *nb_req = get_value_by_tags(parser->root, REQ_OBJ);

    if (!nb_req || !requirement || !dialogue || !q_desc)
        return;
    quest->dialogue = my_strdup(dialogue);
    quest->q_desc = my_strdup(q_desc);
    quest->requirement.number = my_atoi(nb_req);
    quest->requirement.requirement = my_strdup(requirement);
}
