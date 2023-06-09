/*
** EPITECH PROJECT, 2023
** add_quest_to_lst
** File description:
** add_quest_to_lst
*/

#include "rpg.h"

static void init_text(quest_s *quest)
{
    quest->text = sfText_create();
    quest->desc.quest = sfText_create();
    quest->font = sfFont_createFromFile("assets/quest/quest_font.ttf");
    sfText_setFont(quest->text, quest->font);
    sfText_setFont(quest->desc.quest, quest->font);
    sfText_setColor(quest->text, sfWhite);
    sfText_setColor(quest->desc.quest, sfWhite);
    sfText_setCharacterSize(quest->text, 20);
    sfText_setCharacterSize(quest->desc.quest, 15);
    sfText_setString(quest->desc.quest, get_quest_advancement(quest));
}

static char *get_quest_xml(char *npc_name)
{
    char *quest = malloc(sizeof(char) * my_strlen(npc_name) + 5);
    char *temp = my_strdup(npc_name);

    if (!quest || !temp)
        return (NULL);
    my_strupcase(&temp);
    quest[0] = '\0';
    quest = my_strcat(quest, "PNJ_");
    quest = my_strcat(quest, temp);
    free(temp);
    return (quest);
}

static quest_s *get_quest(char *npc_name, rpg_t *rpg)
{
    quest_s *quest = malloc(sizeof(quest_s));
    char *quest_xml = get_quest_xml(npc_name);

    if (!quest || !quest_xml)
        return (NULL);
    quest->name_npc = my_strdup(npc_name);
    quest->xml_npc = my_strdup(quest_xml);
    quest->state = -1;
    quest->requirement.number_get = 0;
    quest->dialogue.parser = 0;
    quest->dialogue.clock_dialogue = 0;
    quest->dialogue.is_talking = false;
    get_xml_info_quest(quest);
    init_text(quest);
    quest->next = NULL;
    quest->prev = rpg->quests->tail;
    return (quest);
}

void add_quest_to_lst(rpg_t *rpg, char *npc_name)
{
    quest_s *quest = get_quest(npc_name, rpg);

    if (!quest || !rpg->quests)
        return;
    if (rpg->quests->size == 0){
        rpg->quests->head = quest;
        rpg->quests->tail = quest;
    } else {
        rpg->quests->tail->next = quest;
        rpg->quests->tail = quest;
    }
    rpg->quests->size++;
}
