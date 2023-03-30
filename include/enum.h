/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_

typedef enum {
    MENU_SCENE,
    SETTINGS_SCENE,
    GAME_SCENE,
    EXIT
} scene_t;

typedef enum {
    MAIN_QUEST,
    BANANA_QUEST
} current_quest_t;

typedef enum {
    WINDOWED,
    FULLSCREEN
} window_mode_t;

#endif /* !ENUM_H_ */
