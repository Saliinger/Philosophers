NAME = philo
CFLAGS = -Wall -Wextra -Werror -I./include/
DEBUG = -g3 #-fsanitize=address
CC = cc
UTILS = ./src/utils
SRCD = ./src

SRC =	$(UTILS)/ft_atoi.c\
		$(UTILS)/ft_free.c\
		$(UTILS)/init.c\
		$(UTILS)/init_philo.c\
		$(UTILS)/utils.c\
		$(SRCD)/eat.c\
		$(SRCD)/sleep.c\
		$(SRCD)/think.c\
		main.c

OBJ =		$(SRC:.c=.o)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
