/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>
    #include <sys/queue.h>

typedef enum {
    IDLE_BUTTON,
    HOVER_BUTTON,
    CLICKED_BUTTON
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
    TAILQ_ENTRY(button_s) next;
} button_t;

#endif /* !STRUCT_H_ */
