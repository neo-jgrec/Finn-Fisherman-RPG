##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

PROJECT_NAME			=	my_rpg
NAME					=	my_rpg

SRC 					:= $(shell find src/ -name '*.c' -type f \
| xargs grep -L "int main")

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

debug:	CFLAGS += -g3
debug:	re

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

re:	fclean all

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
