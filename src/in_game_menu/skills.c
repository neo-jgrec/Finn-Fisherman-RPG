/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** skills
*/

#include "rpg.h"

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list);

static const char *names[] = {"[HEAL POWER]", "[MAX HEALTH]",
"[SPEED]", "[DAMAGE]", "[CRITICAL CHANCE]", "[JUMP]"};

static button_t *search_button(const char *name,
    struct buttons *button_list, int nb_cmp)
{
    button_t *button = NULL;

    TAILQ_FOREACH(button, button_list, next) {
        if (!my_strncmp(button->name, name, nb_cmp))
            return button;
    }
    return NULL;
}

static void update_buttons_name(rpg_t *rpg)
{
    button_t *button = NULL;
    int *all_data[] = {&rpg->data->player_stat.heal_power,
    &rpg->data->player_stat.max_health,
    &rpg->data->player_stat.speed, &rpg->data->player_stat.damage,
    &rpg->data->player_stat.crit_chance, &rpg->data->player_stat.jump};
    for (size_t i = 0; i < ARRAY_SIZE(names); i++) {
        button = search_button(names[i],
            (struct buttons *)&rpg->menu->in_game_menu->skill_buttons,
                my_strlen(names[i]));
        button->name = my_strcat_inf((rpg->data->lvl_point > 0) ? 5 : 4,
            names[i], " -> ", my_itoa(*all_data[i]), " PTS",
            (rpg->data->lvl_point > 0) ? " (LVL UP AVAILABLE)" : "");
        button->size = (sfVector2f){TEXT_SIZE_LEN(button->name, 30), 30};
        if (button->state == HOVER_BUTTON
            && rpg->win->event.type == sfEvtMouseButtonPressed
            && rpg->data->lvl_point > 0) {
            rpg->data->lvl_point--;
            (*all_data[i])++;
        }
    }
}

static void event_manager(win_t *win, rpg_t *rpg)
{
    if (win->event.type == sfEvtClosed) {
        sfRenderWindow_close(win->win);
        rpg->win->scene = NONE;
    }
    sfRenderWindow_setView(win->win, sfRenderWindow_getDefaultView(win->win));
    update_buttons_name(rpg);
}

void draw_characteristics(win_t *win, rpg_t *rpg)
{
    event_manager(win, rpg);
    button_manager(win, rpg, (struct buttons *)&(rpg->menu->in_game_menu
        ->skill_buttons));
    sfText_setString(rpg->menu->in_game_menu->text, my_strcat_inf(2,
        "POINTS TO ATTRIBUTE: ", my_itoa(rpg->data->lvl_point)));
    sfText_setFont(rpg->menu->in_game_menu->text, rpg->menu->font);
    sfText_setPosition(rpg->menu->in_game_menu->text, (sfVector2f)
        {sfRenderWindow_getSize(rpg->win->win).x - (24 * 10), 100});
    sfText_setCharacterSize(rpg->menu->in_game_menu->text, 15);
    sfRenderWindow_drawText(win->win, rpg->menu->in_game_menu->text, NULL);
}
