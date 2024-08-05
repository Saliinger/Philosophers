NAME = philo
CFLAGS = -Wall -Wextra -Werror -pthread -I./include/
DEBUG = -g3 #-fsanitize=address
CC = cc
UTILS = ./src/utils
SIM = ./src/sim
SRCD = ./src

SRC =	$(UTILS)/ft_atoi.c\
		$(UTILS)/ft_free.c\
		$(UTILS)/init.c\
		$(UTILS)/utils.c\
		$(SIM)/init_philo.c\
		$(SIM)/init_write.c\
		$(SIM)/end.c\
		$(SIM)/init_fork.c\
		$(SIM)/routine.c\
		$(SIM)/thread.c\
		$(SIM)/start.c\
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
