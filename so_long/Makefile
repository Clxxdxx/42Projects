NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/so_long.c src/close_window.c src/map_actions.c src/errors/errors_map.c src/errors/error_valid_road.c src/utils.c \
      src/errors/show_map_error.c src/moves.c src/free_map.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = bonus/so_long_bonus.c bonus/close_window_bonus.c bonus/map_actions_bonus.c bonus/errors_bonus/errors_map_bonus.c bonus/errors_bonus/error_valid_road_bonus.c bonus/utils_bonus.c \
            bonus/errors_bonus/show_map_error_bonus.c bonus/moves_bonus.c bonus/free_map_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

MLX_DIR = minilibx-linux/minilibx-linux
LIBFT_DIR = libft
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR) -I $(MLX_DIR)

LIBS = $(MLX_LIB) $(LIBFT_LIB) -lXext -lX11 -lm

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(INCLUDES) $(LIBS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
