##
## EPITECH PROJECT, 2019
## PSU_105torus_2019
## File description:
## Makefile
##

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"
WARNING				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\x1b[0m"
ATTENTION			= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\x1b[0m"
ERROR				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\x1b[0m"
DONE				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"


## ========================================================================== ##
PATH_INIT		=	./sources/initialisation/
INIT			=	basics.c										\
					main.c


## ========================================================================== ##
SRC				=	$(addprefix $(PATH_INIT), $(INIT))


.PHONY:			 all, fclean, clean, re, library, tests_run

BIN				= 	105torus

CC				= 	@gcc

INCLUDE_DIR		=	./include

CFLAGS			=	-g -I./include/ -D_GNU_SOURCE -Wall -Wextra -pedantic -O3 -O2 -Wunused

LDFLAGS 		= 	-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

FLAGS			=	$(CFLAGS) -I$(INCLUDE_DIR) -lm -L./lib -lmy -Llib -lmy_printf

UT_SRC			=	$(SRC)

UT_OBJ			=	$(UT_SRC:.c=.o)

UT_FLAGS		=	$(CFLAGS) -lcriterion -lgcov --coverage $(FLAGS)

all:			library $(BIN)

library:
				@$(MAKE) -C ./lib/my/
				@$(MAKE) -C ./lib/my_printf/

$(BIN):			$(SRC)
				@$(CC) -o $(BIN) $(SRC) $(FLAGS) $(LDFLAGS) $(CFLAGS)
				@$(call SUCCESS, "The binary has been created correctly.")

clean:			clean_lib_obj
				@$(RM) *.vgcore
				@$(RM) *.gc*
				@$(call DONE, "[ DONE 100% ]")

clean_lib:
				@$(MAKE) clean_lib -C ./lib/my/
				@$(MAKE) clean_lib -C ./lib/my_printf/

clean_lib_obj:
				@$(MAKE) clean -C ./lib/my/
				@$(MAKE) clean -C ./lib/my_printf/

fclean:			clean clean_lib
				@$(RM) $(BIN)
				@$(call SUCCESS, "[ DONE ] All library cleaned.")

re:				fclean all

run:
				./$(BIN) game_map/game

valgrind:
				valgrind ./$(BIN) game_map/game

tests_run:
				gcc -o $(UT_FLAGS) $(UT_OBJ)
				./units