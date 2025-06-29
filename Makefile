NAME = push_swap

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I. -I$(LIBFT_DIR)
LIBS = $(LIBFT)

SRCS = main.c \
	parse_validate.c \
	coordinate_compression.c \
	stack_creation.c \
	stack_utils.c \
	solver.c \
	sort_small.c \
	sort_large.c \
	sort_utils.c \
	chunk_utils.c \
	op_push.c \
	op_rotate.c \
	op_reverse_rotate.c \
	op_swap.c \
	move_cost.c \
	execute_move.c \
	utils.c


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
