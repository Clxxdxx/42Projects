NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = so_long.c window_actions/close_window.c map_actions/utils.c
OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux/minilibx-linux
LIBFT_DIR = libft
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR) -I $(MLX_DIR)

LIBS = $(MLX_LIB) $(LIBFT_LIB) -lXext -lX11 -lm

all: $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
