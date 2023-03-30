##
## EPITECH PROJECT, 2023
## mars_lib
## File description:
## Makefile
##

include src/main.mk
include src/puts/puts.mk
include src/basics/basics.mk
include src/flags/flags.mk

PROJECT_NAME			=	my_printf
NAME					=	libprintf.a

BUILD_DIR				=	build
OBJ						=	$(SRC:%.c=$(BUILD_DIR)/%.o)

CFLAGS					=	-I include/
WFLAGS					=	-Wall -Wextra

CRITERION				=	-lcriterion --coverage
TEST_SRC				=	tests/test.c
TEST_NAME				=	unit_tests
BUILD_TESTS_DIR			=	$(BUILD_DIR)/tests
TESTS_OBJ				=	$(TEST_SRC:%.c=$(BUILD_DIR)/%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)\
	&& echo -e "\033[1;32m[SUCCES]\033[0m" $(NAME)\
	|| echo -e "\033[1;31m[ERROR]\033[0m" $(NAME)

$(BUILD_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	@gcc -c -o $@ $< $(CFLAGS) $(WFLAGS)\
	&& echo -e "\033[1;32m[OK]\033[0m" $<\
	|| echo -e "\033[1;31m[KO]\033[0m" $<

debug:	CFLAGS += -g
debug:	re

clean:
	@for file in $(BUILD_DIR)/*; do\
		if [ -d $$file ]; then\
			rm -rf $$file;\
			echo -e "\033[1;31m[DELETED]\033[0m" $$file;\
		fi;\
	done
	@echo -e "\033[1;31m[CLEAN]\033[0m" $(PROJECT_NAME)
	@rm -f $(shell find -name '*.gc*' -type f)

fclean: clean
	@rm -f $(TEST_NAME)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(TEST_NAME)
	@rm -rf $(BUILD_DIR)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(BUILD_DIR)
	@rm -f $(NAME)
	@echo -e "\033[1;31m[DELETED]\033[0m" $(NAME)

re:	fclean all

tests_run:	CFLAGS += -lcriterion --coverage
tests_run:	fclean
	@if [ ! -d "tests" ]; then\
		echo -e "\033[1;31m[ERROR]\033[0m" "No tests directory";\
		exit 1;\
	fi
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_TESTS_DIR)
	@gcc -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(CFLAGS) $(WFLAGS) $(CRITERION)\
	&& echo -e "\033[1;32m[OK]\033[0m" $(TEST_NAME)\
	|| echo -e "\033[1;31m[KO]\033[0m" $(TEST_NAME)
	@./$(TEST_NAME)
	mv *.gc* $(BUILD_TESTS_DIR)
	gcovr --exclude tests/

.PHONY: all clean fclean re debug tests_run

.SILENT: all clean fclean re debug tests_run

%:
	@echo -e "\033[1;31m[ERROR]\033[0m" "No rule to make target '$@'"
