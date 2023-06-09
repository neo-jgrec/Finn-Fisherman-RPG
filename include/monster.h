/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** monster
*/

#ifndef MONSTER_H_
    #define MONSTER_H_

    #include "rpg.h"

typedef struct monster_stat_s {
    sfVector2f pos;
    int damage;
    int life;
    int loot;
    char *drop_list;
} monster_stat_t;

void init_monsters(rpg_t *rpg);
void init_mas(asset_t *asset);
void init_mas_2(asset_t *asset);
void free_monsters(rpg_t *rpg);

void manage_monster(win_t *win, rpg_t *rpg);

void init_skeleton(rpg_t *rpg,
    entity_t *monster, monster_stat_t stat);
void init_eye(rpg_t *rpg,
    entity_t *monster, monster_stat_t stat);
void init_shroom(rpg_t *rpg,
    entity_t *monster, monster_stat_t stat);
void init_troll(rpg_t *rpg,
    entity_t *monster, monster_stat_t stat);
void init_ball(rpg_t *rpg,
    entity_t *monster, monster_stat_t stat);
void init_slash(rpg_t *rpg,
    entity_t *monster, monster_stat_t stat);

void add_monster(rpg_t *rpg, id_entity id, monster_stat_t stat);
void draw_monsters(rpg_t *rpg);

void set_var_skeleton(entity_t *monster, rpg_t *rpg);
void set_sprite_skeleton(entity_t *player, rpg_t *rpg);
void set_var_eye(entity_t *monster, rpg_t *rpg);
void set_sprite_eye(entity_t *player, rpg_t *rpg);
void set_var_shroom(entity_t *monster, rpg_t *rpg);
void set_sprite_shroom(entity_t *player, rpg_t *rpg);
void set_var_troll(entity_t *monster, rpg_t *rpg);
void set_sprite_troll(entity_t *player, rpg_t *rpg);
void set_var_ball(entity_t *monster, rpg_t *rpg);
void set_sprite_ball(entity_t *player, rpg_t *rpg);
void set_var_slash(entity_t *monster, rpg_t *rpg);
void set_sprite_slash(entity_t *player, rpg_t *rpg);
void monster_drop(rpg_t *rpg, entity_t *entity);
void set_death(rpg_t *rpg, entity_t *entity);
void eye_attack(rpg_t *rpg, entity_t *monster);
void shroom_attack(rpg_t *rpg, entity_t *monster);
void troll_attack(rpg_t *rpg, entity_t *monster);
void flip_monster(entity_t *monster, entity_t *player);

#endif /* !MONSTER_H_ */
