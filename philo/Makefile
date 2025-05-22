NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/philo.c src/initializer.c src/forks_functions.c src/parse.c \
      src/create_threads.c src/wait_thread_finish.c src/utils.c src/philo_actions.c \
      src/free_resources.c src/errors.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
