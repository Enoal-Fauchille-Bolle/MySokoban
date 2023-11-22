##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## day10
##

SRC	=	my_printf.c	\
		printing.c	\
		separate_modifiers_from_str.c	\
		specifier_b_maj.c	\
		specifier_b.c	\
		specifier_c.c	\
		specifier_e_maj.c	\
		specifier_e.c	\
		specifier_f_maj.c	\
		specifier_f.c	\
		specifier_i_and_d.c	\
		specifier_n.c	\
		specifier_o.c	\
		specifier_p.c	\
		specifier_percent.c	\
		specifier_s.c	\
		specifier_u.c	\
		specifier_x_maj.c	\
		specifier_x.c	\
		utilities_modifiers.c	\
		get_nbrlen.c	\
		my_str_char_counter.c	\
		convert_base.c	\
		my_put_nbr2.c	\
		my_put_nbr_u.c	\
		my_slice.c	\
		my_strcpy.c	\
		my_compute_power_rec.c	\
		my_revstr.c	\
		exponent.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_str_get_index.c	\
		my_str_include.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_printf.a

CFLAGS += -I./ -I../../include/ -Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my_printf.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
