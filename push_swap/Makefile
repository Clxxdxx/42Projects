NAME = push_swap

CC = cc
CCFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c rules/initializer.c rules/push.c rules/reverse.c \
	  rules/rotate.c rules/swap.c algorithm/ksort.c algorithm/utils.c \
	  errors/error_duplicate_number.c errors/error_non_integer.c \
	  errors/error_out_of_range.c errors/show_error.c free_args.c \
	  algorithm/order_three_nums.c algorithm/counts.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I. -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf -I$(LIBFT_DIR)/get_next_line

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): 
	make -C $(LIBFT_DIR) all

bonus: all

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean re all bonus
