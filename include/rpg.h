/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg.h
*/

#ifndef _RPG_H__
    #define _RPG_H__
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <SFML/Config.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/Window.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Joystick.h>
    #include <SFML/Window/Keyboard.h>

    #include <math.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <time.h>

    #include "mars.h"
    #include "xml_parser.h"
    #include "win.h"
    #include "puzzle.h"
    #include "asset.h"
    #include "entity.h"
    #include "player.h"
    #include "monster.h"
    #include "loading.h"
    #include "input.h"
    #include "data.h"
    #include "menu.h"
    #include "mars.h"
    #include "fishing.h"
    #include "parallax.h"
    #include "npc.h"
    #include "song.h"
    #include "quests.h"
    #include "destroy.h"
    #include "shaders.h"

    #define SEC(time) ((float)(time) / 1000000)
    #define DELTAT(time) (SEC(sfClock_getElapsedTime(time).microseconds))
    #define VEC sfVector2f
    #define NB_MAP 2

    typedef enum weather {
        NONE_WEATHER,
        RAIN,
        SNOW
    } weather_e;

    typedef struct rpg_s {
        win_t *win;
        puzzle_t *puzzle;
        data_t *data;
        asset_t *asset;
        entity_t *player;
        entity_t **monsters;
        item_e **items;
        loading_t *loading;
        input_t *input;
        menu_t *menu;
        fishing_t *fishing;
        parall_t *parall;
        npc_t *npc;
        quest_t *quests;
        music_t *music;
        int music_volume;
        int sound_volume;
        char *save_path;
        all_shaders_t *shaders;
        sfRectangleShape *shader_layer;
        weather_e weather;
    } rpg_t;

    int rpg(void);

    int main_loop(win_t *win, rpg_t *rpg);
    void menu_loop(win_t *win, rpg_t *rpg);

    void scene_manager(rpg_t *rpg);

    void draw(win_t *win, rpg_t *rpg);

    rpg_t *init_rpg(void);

    int my_random(int min, int max);
    float get_dist(VEC pos_1, VEC pos_2);
    void a_freestw(char **stw);
    char **a_mkstw(char *str, char *sep);
    sfFloatRect *add_colliders(sfFloatRect *colliders,
        sfFloatRect rect, int *nb_col);
    int get_xml_int(xml_parser_t *parser, char **tags);
    void switch_weather(rpg_t *rpg);

#endif /* !_RPG_H__ */
