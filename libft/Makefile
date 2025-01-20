NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard ft_*.c)
$(info SRC = $(SRC))
OBJ = $(SRC:.c=.o)
INCLUDE = libft.h
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

phony: clean fclean re