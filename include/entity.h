/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "rpg.h"

    typedef enum entity_state_s {
        IDLE,
        RUN,
        ROLL,
        JUMP_1,
        JUMP_2,
        ATTACK,
        HEALING,
        HIT
    } p_state_e;

    typedef enum id_s {
        PLAYER,
        MONSTER_1
    } id_e;

    typedef struct frame_s {
        int size;
        int nb;
        float cd;
        int loop;
        void (*action)(rpg_t *, entity_t *);
    } frame_t;

    typedef struct jump_s {
        int nb;
        int save;
        float press_time;
        float ground_time;
    } jump_t;

    typedef struct roll_s {
        int save;
        int save_dir;
        float press_time;
        float cd;
    } roll_t;

    typedef struct health_s {
        int save_heal;
        float cd;
        float damage_cd;
        float not_moving;
        sprite_t hud;
        sprite_t health_hud;
        sprite_t potion_hud;
        sprite_t xp_hud;
        sfText *lvl_hud;
        int health;
        int potion;
    } health_t;

    typedef struct attack_s {
        int save;
        int crit;
    } attack_t;

    typedef struct entity_s {
        id_e id;
        p_state_e state;
        p_state_e prev_state;
        sfSprite *sp;
        sfFloatRect rect;
        sfVector2f pos;
        float time;
        frame_t frame;
        jump_t jump;
        roll_t roll;
        health_t health;
        attack_t attack;
        int hor;
        int dir;
        int grounded;
        float velocity;
        struct entity_s *next;
    } entity_t;

    void set_position(win_t *win, entity_t *player, rpg_t *rpg);

#endif /* !ENTITY_H_ */
