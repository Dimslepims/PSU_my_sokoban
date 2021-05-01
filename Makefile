##
## EPITECH PROJECT, 2019
## makz
## File description:
## makz
##

SRC =	src/sokoban.c	\
		src/my_strlen.c	\
		src/my_malloc.c	\
		src/check_o.c	\
		src/player.c	\
		src/ncurses.c	\
		src/error.c	\
		src/open_read.c	\
		src/descript.c	\
		src/my_putstr.c

NAME =	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) $(SRC) -lncurses

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re : fclean all
