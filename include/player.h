/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** player
*/

#ifndef _PLAYER_H__
    #define _PLAYER_H__

    #include "rpg.h"

    typedef struct rpg_s rpg_t;

    typedef enum player_state_s {
        IDLE,
        RUN,
        ROLL,
        JUMP_1,
        JUMP_2,
        ATTACK,
        HEALING
    } p_state_t;

    typedef struct frame_s {
        int size;
        int nb;
        float cd;
        int loop;
        void (*action)(rpg_t *);
    } frame_t;

    typedef struct stat_s {
        int speed;
    } stat_t;

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
        float not_moving;
        sprite_t hud;
        sprite_t health_hud;
        sprite_t potion_hud;
        sprite_t xp_hud;
        sfText *lvl_hud;
        int health;
        int potion;
    } health_t;

    typedef struct player_s {
        p_state_t state;
        p_state_t prev_state;
        sfSprite *sp;
        sfFloatRect rect;
        sfVector2f pos;
        float time;
        frame_t frame;
        jump_t jump;
        roll_t roll;
        health_t health;
        int hor;
        int dir;
        int grounded;
        float velocity;
    } player_t;

    void init_player(asset_t *asset, rpg_t *rpg);

    void manage_player(win_t *win, player_t *player, rpg_t *rpg);
    void move_player(player_t *player, sfVector2f dir);
    void manage_jump(player_t *player, rpg_t *rpg);
    void manage_roll(player_t *player, rpg_t *rpg);
    void manage_heal(player_t *player, rpg_t *rpg);
    void heal_anim(rpg_t *rpg);

    void set_animation(player_t *player, sprite_t sprite, int loop,
        void (*action)(rpg_t *));
    void set_sprite(player_t *player, rpg_t *rpg);
    void return_to_idle(rpg_t *rpg);

    void draw_player_hud(player_t *player, rpg_t *rpg);

#endif /* !_PLAYER_H__ */
