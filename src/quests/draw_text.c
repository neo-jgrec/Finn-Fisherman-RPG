/*
** EPITECH PROJECT, 2023
** draw_text
** File description:
** draw_text
*/

#include "rpg.h"

static void change_state_draw(rpg_t *rpg)
{
    if (rpg->quests->draw)
        rpg->quests->draw = false;
    else
        rpg->quests->draw = true;
    rpg->quests->clock_input = 0;
}

void draw_text(rpg_t *rpg)
{
    quest_s *temp = rpg->quests->head;
    rpg->quests->clock_input += rpg->win->deltaT;
    float pos_x = rpg->player->pos.x + 550;
    float pos_y = rpg->player->pos.y - 600;

    if (rpg->input->quest.press && rpg->quests->clock_input > 0.5)
        change_state_draw(rpg);
    for (; temp; temp = temp->next) {
        if (temp->dialogue.is_talking)
            sfRenderWindow_drawText(rpg->win->win, temp->text, NULL);
        if (!rpg->quests->draw)
            continue;
        if (temp->state == 0) {
            sfText_setPosition(temp->desc.quest, (sfVector2f){pos_x, pos_y});
            sfRenderWindow_drawText(rpg->win->win, temp->desc.quest, NULL);
            pos_y += 25;
        }
    }
}
