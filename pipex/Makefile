NAME = pipex
CC = cc
CCFLAGS = -Wall -Wextra -Werror
SRC = pipex.c pipex_utils.c libft_utils/ft_split.c libft_utils/ft_strcat.c \
		libft_utils/ft_strcpy.c libft_utils/ft_strdup.c libft_utils/ft_strlen.c \
		libft_utils/ft_strncmp.c
OBJ = $(SRC:.c=.o)
INCLUDE = pipex.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
