NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/philo.c src/initializer.c src/forks_functions.c src/parse.c src/init_time.c \
		src/create_threads.c src/wait_thread_finish.c src/utils.c src/monitor_thread.c \
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C clean

fclean: clean
	rm -f $(NAME)
	make -C fclean

re: fclean all

.PHONY: all bonus clean fclean re
