/*
** EPITECH PROJECT, 2023
** draw_text
** File description:
** draw_text
*/

#include "rpg.h"

void draw_text(rpg_t *rpg)
{
    quest_s *temp = rpg->quests->head;

    for (; temp; temp = temp->next)
        if (temp->dialogue.is_talking)
            sfRenderWindow_drawText(rpg->win->win, temp->text, NULL);
}
