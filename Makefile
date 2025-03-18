NAME = push_swap
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c\
		stack.c\
		sort_utils.c\
		radix.c\
		operations.c\
		init_utils.c\
		utils.c\
		sort.c

OBJS = $(SRCS:.c=.o)
LIBFT = lib/libft.a

all: $(NAME)
	@echo "Building all..."

$(NAME): $(OBJS) $(LIBFT)
	@echo "Creating executable..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@make -C lib

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C lib clean

fclean: clean
	@echo "Removing executable and cleaning..."
	@rm -f $(NAME)
	@make -C lib fclean

re: fclean all
	@echo "Rebuilding all..."

.PHONY: all clean fclean re
