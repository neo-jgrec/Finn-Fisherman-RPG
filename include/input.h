/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** input
*/

#ifndef INPUT_H_
    #define INPUT_H_

    #include "rpg.h"

    typedef struct key_value_s {
        sfKeyCode code;
        int press;
    } kv_t;

    typedef struct input_s {
        kv_t left;
        kv_t right;
        kv_t roll;
        kv_t jump;
        kv_t heal;
        kv_t interact;
        kv_t attack;
        kv_t fish_up;
        kv_t fish_down;
    } input_t;

    void init_input(rpg_t *rpg);

    void check_input(win_t *win, input_t *input);

#endif /* !INPUT_H_ */
