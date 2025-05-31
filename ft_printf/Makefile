NAME = libftprintf.a

SRCS = ft_printf.c \
       utils_printf.c \
			 utils_hex_pointer.c \
       handle_hex_pointer.c \
			 handle_integer.c \
			 handle_char_string.c \
      #  ft_itoa.c\
      #  ft_strlen.c\


OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(LIBFT_A):
			$(MAKE) -C $(LIBFT_DIR)
			cp $(LIBFT_A) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
