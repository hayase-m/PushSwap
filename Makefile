NAME = push_swap

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Iinclude -I$(LIBFT_DIR)
LIBS = $(LIBFT)

SRCS = src/main.c \
	src/parse_validate.c \
	src/coordinate_compression.c \
	src/input_processing.c \
	src/stack/stack_creation.c \
	src/stack/stack_utils.c \
	src/sorting/solver.c \
	src/sorting/sort_small.c \
	src/sorting/sort_large.c \
	src/sorting/sort_utils.c \
	src/sorting/chunk_utils.c \
	src/operations/op_push.c \
	src/operations/op_rotate.c \
	src/operations/op_reverse_rotate.c \
	src/operations/op_swap.c \
	src/sorting/move_cost.c \
	src/sorting/execute_move.c \
	src/utils.c


OBJS = $(SRCS:.c=.o)

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
