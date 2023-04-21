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
    float pos_x = rpg->player->pos.x + 550;
    float pos_y = rpg->player->pos.y - 600;

    for (; temp; temp = temp->next) {
        if (temp->dialogue.is_talking)
            sfRenderWindow_drawText(rpg->win->win, temp->text, NULL);
        if (temp->state == 0) {
            sfText_setPosition(temp->desc.quest, (sfVector2f){pos_x, pos_y});
            sfRenderWindow_drawText(rpg->win->win, temp->desc.quest, NULL);
            pos_y += 25;
        }
    }
}
