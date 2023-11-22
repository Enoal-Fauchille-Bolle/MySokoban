##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## day10
##

SRC	=	exponent.c  \
		my_compute_power_rec.c	\
		my_compute_square_root.c    \
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_str_isalpha.c	\
		my_str_isnum.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_str_to_word_array.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_word_to_array.c	\
		my_slice.c	\
		my_str_include.c	\
		my_strip.c	\
		my_right_strip.c	\
		my_left_strip.c	\
		my_str_get_index.c	\
		my_sort_str_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a
# NAME	=	libmy.so

CFLAGS += -I./ -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	# gcc -shared -o $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
