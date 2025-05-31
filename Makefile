NAME = push_swap

LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LIBS = $(PRINTF_LIB) $(LIBFT)

SRCS = main.c \


OBJS = $(SRCS:.c=.o)

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean:
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(PRINTF_LIB) $(LIBFT)
