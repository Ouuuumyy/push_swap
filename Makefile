NAME = push_swap

SRCS = parsing.c \
       push_swap.c \
       sorting_small_stacks.c \
       sorting_large_stacks.c \
       sorting_special_cases.c \
       split.c \
       libft.c \
       stack_operations.c \
       stack_to_array.c \
       stack_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re