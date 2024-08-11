NAME = philo
CFLAGS += -Wall -Wextra -Werror -pthread -I./include/
DEBUG += -g3 #-fsanitize=address #-fsanitize=thread
CC = cc
UTILS = ./src/utils
SIM = ./src/sim
SRCD = ./src

SRC =	$(UTILS)/ft_atol.c\
		$(UTILS)/ft_free.c\
		$(UTILS)/init_data.c\
		$(UTILS)/utils.c\
		$(SIM)/init_philo.c\
		$(SIM)/end.c\
		$(SIM)/init_mutex.c\
		$(SIM)/monitor.c\
		$(SIM)/routine.c\
		$(SIM)/thread.c\
		$(SIM)/start.c\
		$(SIM)/actions.c\
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
