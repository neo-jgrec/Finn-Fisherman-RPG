##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

PROJECT_NAME			=	my_rpg
NAME					=	my_rpg

SRC 					:=	src/main_loop.c \
							src/rpg.c \
							src/loading_screen.c \
							src/check_input.c \
							src/draw_map.c \
							src/draw.c \
							src/get_random.c \
							src/scene_manager.c \
							src/set_position.c \
							src/dist.c \
							src/a_stw.c \
							src/free_stw.c \
							src/add_collider.c \
							src/get_xml_int.c

SRC						+=	src/init/init_rpg.c \
							src/init/init_win.c \
							src/init/init_puzzle.c \
							src/init/init_asset.c \
							src/init/init_player.c \
							src/init/init_loading.c \
							src/init/init_sprite.c \
							src/init/init_input.c \
							src/init/init_data.c \
							src/init/init_map.c \
							src/init/init_menu.c \
							src/init/init_fishing.c	\
							src/init/init_npc.c	\
							src/init/init_monster_asset.c \
							src/init/init_skeleton.c \
							src/init/init_eye.c \
							src/init/init_shroom.c	\
							src/init/init_saves.c \
							src/init/init_fish_spot.c \
							src/init/init_song.c \
							src/init/init_parall.c \
							src/init/init_shaders.c \
							src/init/init_sign.c \
							src/init/init_monsters.c

SRC						+=  src/init/npc/init_merchant.c	\
							src/init/npc/init_priest.c	\
							src/init/npc/init_chef.c	\
							src/init/npc/init_alchemist.c	\
						    src/init/npc/init_npc_sprites.c

SRC						+=  src/init/quests/add_quest_to_lst.c \
							src/init/quests/get_xml_info_quest.c \
							src/init/quests/init_quest.c \
							src/init/quests/my_strupcase.c

SRC						+=	src/player/manage_jump.c \
							src/player/manage_roll.c \
							src/player/check_collision.c \
							src/player/manage_player.c \
							src/player/move_player.c \
							src/player/on_ground.c \
							src/player/draw_player_hud.c \
							src/player/draw_button_hud.c \
							src/player/manage_heal.c \
							src/player/hit_player.c \
							src/player/manage_attack.c \
							src/player/check_monster_collision.c \
							src/player/check_spikes_collision.c \
							src/player/check_fishing_spot.c \
							src/player/manage_fishing.c \
							src/player/draw_youdead.c \
							src/player/check_sign.c \
							src/player/set_stat.c \
							src/player/check_items.c

SRC						+=	src/player/anim/set_anim.c \
							src/player/anim/set_sprite.c \
							src/player/anim/return_to_idle.c \
							src/player/anim/heal_anim.c \
							src/player/anim/death_anim.c \
							src/player/anim/attack_anim.c \
							src/player/anim/flip_sprite.c

SRC						+=	src/fishing/start_fishing_minigame.c \
							src/fishing/make_keep_zone_move.c \
							src/fishing/move_fish.c \
							src/fishing/change_zone_color.c	\
							src/fishing/end_fishing_game.c

SRC						+=	src/destroy_rpg/destroy_rpg.c \
							src/destroy_rpg/free_fishing.c \
							src/destroy_rpg/free_window.c \
							src/destroy_rpg/free_quest.c \
							src/destroy_rpg/free_song.c

SRC						+=	src/window/cam_management.c \
							src/window/switch_size.c \
							src/window/switch_style.c

SRC 					+= 	src/map_parser/map_parser.c

SRC						+=	src/song/manage_song.c

SRC						+= 	src/menu/menu_loop.c		\
							src/menu/buttons/manager.c	\
							src/menu/buttons/functions.c \
							src/menu/buttons/functions_settings.c \
							src/menu/buttons/functions_res.c	\
							src/menu/saves.c \
							src/menu/button_save_manager.c	\
							src/menu/buttons/saves_action.c

SRC 					+=	xml_parser/edit_value.c \
							xml_parser/free.c \
							xml_parser/init.c \
							xml_parser/node_parsing.c \
							xml_parser/parser.c \
							xml_parser/update_xml.c \
							xml_parser/utils.c

SRC						+=	src/monsters/add_monster.c \
							src/monsters/draw_monsters.c \
							src/monsters/manage_monster.c \

SRC						+=	src/monsters/skeleton/manage_skeleton.c \
							src/monsters/skeleton/set_sprite_skeleton.c \

SRC						+=	src/monsters/eye/manage_eye.c \
							src/monsters/eye/set_sprite_eye.c

SRC						+=	src/monsters/shroom/manage_shroom.c \
							src/monsters/shroom/set_sprite_shroom.c

SRC						+=  src/npc/manage_npc.c \
							src/npc/display_npc.c \
							src/npc/verify_state_npc.c	\
							src/npc/animate_npc.c

SRC 					+=	src/utils/is_rect_hover.c	\
							src/utils/read_folder.c

SRC 					+=	src/saves/create_save.c		\
							src/saves/check.c

SRC						+=	src/parallax/draw_parall.c \
							src/parallax/manage_parall.c

SRC						+=	src/free/free_puzzle.c \
							src/free/free_entity.c \
							src/free/free_monsters.c \
							src/free/free_items.c

SRC						+=	src/item/add_item.c \
							src/item/manage_items.c \
							src/item/draw_items.c

MAIN 					= 	src/main.c

BUILD_DIR				=	build
OBJ						=	$(SRC:%.c=$(BUILD_DIR)/%.o) \
$(MAIN:%.c=$(BUILD_DIR)/%.o)

LIB_FOLDER				=	mars_lib

CFLAGS					:=	-I include/ 							\
							-I $(LIB_FOLDER)/include/				\
							-I $(LIB_FOLDER)/my_printf/include/		\
							-I $(LIB_FOLDER)/my_stdlib/include/		\
							-I $(LIB_FOLDER)/my_arraylib/include/	\


WFLAGS					:=	-Wall -Wextra

LDLIBS					:=	-L $(LIB_FOLDER) -lmars

CRITERION				=	-lcriterion --coverage
TEST_SRC				=	tests/basics.c
TEST_NAME				=	unit_tests
BUILD_TESTS_DIR			=	$(BUILD_DIR)/tests
TESTS_OBJ				=	$(TEST_SRC:%.c=$(BUILD_DIR)/%.o)
CSFML 					= 	-lcsfml-window -lcsfml-graphics \
							-lcsfml-system -lcsfml-audio -lm

default:
	@$(MAKE) -j all --no-print-directory

all:	$(NAME)

$(NAME):	$(OBJ)
	@mkdir -p $(BUILD_DIR)
	@make -s -C $(LIB_FOLDER)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS) $(LDLIBS) \
	$(CSFML) \
	&& echo -e "\033[1;32m[OK]\033[0m" $(NAME)\
	|| echo -e "\033[1;31m[KO]\033[0m" $(NAME)

$(BUILD_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CFLAGS) $(WFLAGS) \
	$(CSFML) \
	&& echo -e "\033[1;32m[OK]\033[0m" $<\
	|| echo -e "\033[1;31m[KO]\033[0m" $<

debug: CFLAGS += -g -O0
debug: fclean all

clean:
	@make -s -C $(LIB_FOLDER) clean
	@echo -e "\033[1;31m[LIB CLEAN]\033[0m" $(LIB_FOLDER)
	@for file in $(BUILD_DIR)/*; do\
		if [ -d $$file ]; then\
			rm -rf $$file;\
			echo -e "\033[1;31m[DELETED]\033[0m" $$file;\
		fi;\
	done
	@echo -e "\033[1;31m[CLEAN]\033[0m" $(PROJECT_NAME)
	@rm -f $(shell find -name '*.gc*' -type f)

fclean: clean
	@make -s -C $(LIB_FOLDER) fclean
	@echo -e "\033[1;31m[LIB FCLEAN]\033[0m" $(LIB_FOLDER)
	@rm -f $(TEST_NAME)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(TEST_NAME)
	@rm -rf $(BUILD_DIR)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(BUILD_DIR)
	@rm -f $(NAME)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) default --no-print-directory

tests_run:	CFLAGS += -lcriterion --coverage
tests_run:	re
	@if [ ! -d "tests" ]; then\
		echo -e "\033[1;31m[ERROR]\033[0m" "No tests directory";\
		exit 1;\
	fi
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_TESTS_DIR)
	@gcc -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(CFLAGS) $(WFLAGS) $(CRITERION) \
	$(LDLIBS)\
	&& echo -e "\033[1;32m[OK]\033[0m" $(TEST_NAME)\
	|| echo -e "\033[1;31m[KO]\033[0m" $(TEST_NAME)
	@./$(TEST_NAME)
	mv *.gc* $(BUILD_TESTS_DIR)
	gcovr --exclude tests/ --exclude $(LIB_FOLDER)/

.PHONY: all clean fclean re debug tests_run

.SILENT: all clean fclean re debug tests_run

%:
	@echo -e "\033[1;31m[ERROR]\033[0m" "No rule to make target '$@'"
