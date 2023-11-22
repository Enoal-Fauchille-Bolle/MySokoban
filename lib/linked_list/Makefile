##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## day10
##

SRC	=	my_show_list.c	\
		my_put_in_list.c	\
		my_apply_on_matching_nodes.c	\
		my_apply_on_nodes.c	\
		my_find_node.c	\
		my_list_size.c	\
		my_params_to_list.c	\
		my_rev_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	liblinked_list.a

CFLAGS += -I./ -I../my/ -Werror -Wall -Wextra -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp linked_list.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
