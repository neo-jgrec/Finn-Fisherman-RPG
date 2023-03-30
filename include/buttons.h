/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>

typedef enum {
    IDLE,
    HOVER,
    CLICKED
} button_state_t;

typedef struct button_textures_s {
    sfTexture *hover;
    sfTexture *clicked;
    sfTexture *idle;
} button_textures_t;

typedef struct button_s {
    char *name;
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *shape;
    button_state_t state;
    button_textures_t textures;
    void (*action)(void *);
    // here linked list of buttons
} button_t;

#endif /* !STRUCT_H_ */
