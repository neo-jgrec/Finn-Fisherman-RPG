/*
** EPITECH PROJECT, 2023
** get_quest_advancement
** File description:
** get_quest_adavncement
*/

#include "rpg.h"

char *get_quest_advancement(quest_s *quest)
{
    char *adv = malloc(sizeof(char) * my_strlen(quest->desc.q_desc) +
    my_nbrlen(REQ.number_get) + my_nbrlen(REQ.number_req) + 5);

    if (!adv)
        return (NULL);
    adv[0] = '\0';
    adv = my_strcat(adv, quest->desc.q_desc);
    adv = my_strcat(adv, " ");
    adv = my_strcat(adv, my_nbr_to_str(REQ.number_get));
    adv = my_strcat(adv, " / ");
    adv = my_strcat(adv, my_nbr_to_str(REQ.number_req));
    return (adv);
}
