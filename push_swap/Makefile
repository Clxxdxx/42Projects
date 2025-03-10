NAME = push_swap
CC = cc
CCFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC = print_stacks.c push_swap.c rules/initializer.c rules/push.c rules/reverse.c \
	  rules/rotate.c rules/swap.c algorithm/ksort.c  algorithm/utils.c \
	  algorithm/partition.c algorithm/pushes.c errors/error_duplicate_number.c \
	  errors/error_non_integer.c errors/error_out_of_range.c errors/show_error.c \
	  free_args.c algorithm/order_mayor_minor_stackb.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I. -Ilibft -Ilibft/ft_printf -Ilibft/get_next_line

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C libft

bonus: all

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean re all bonus
