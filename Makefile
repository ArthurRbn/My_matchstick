##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/my_putstr.c \
		src/my_putchar.c\
		src/my_strlen.c \
		src/my_getnbr.c \
		src/nbr_to_str.c\
		src/matchstick.c\
		src/print_matchstick.c	\
		src/matchstick_update.c \
		src/matchstick_set_game.c	\
		src/error_handling.c	\
		src/matchstick_ia.c	\
		src/ia_moves.c	\
		src/my_put_nbr.c	\
		src/my_printf.c	\
		src/printf_flags.c	\
		src/printf_flags2.c	\
		src/printf_flags3.c	\
		src/printf_flags4.c	\
		src/my_revstr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o  $(NAME) -Wall -Wextra $(OBJ) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all