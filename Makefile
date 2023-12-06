##
## EPITECH PROJECT, 2023
## MySokoban
## File description:
## Makefile
##

SRC	=	main.c	\
		mysokoban.c	\
		map_parsing.c	\
		game_display.c	\
		game_movements.c	\
		map_checking.c	\
		game_checking.c	\

SRC_TESTS =	tests/test.c	\
		mysokoban.c	\
		parsing.c	\
		display.c	\
		movement.c	\
		checking.c	\

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

CFLAGS += -I./include/ -Werror -Wall -Wextra

FLAGS_TEST = -L./lib/my -lmy -L./lib/my_printf	\
			-lmy_printf -L./lib/linked_list -llinked_list	\
			-lcriterion --coverage -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/my_printf/
	make -C lib/linked_list/
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -L./lib/my_printf	\
	-lmy_printf -L./lib/linked_list -llinked_list -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

unit_tests: re
	gcc -o unit_tests $(SRC_TESTS) $(CFLAGS) $(FLAGS_TEST)

tests_run: unit_tests
	./unit_tests
