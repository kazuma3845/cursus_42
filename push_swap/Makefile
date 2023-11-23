NAME := push_swap

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := srcs/*.c
GETNEXTLINE := gnl/*c
PRINTF := ft_printf/*c
LIBFT := libft/*c

all:
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF) $(LIBFT) -o $(NAME)

clean:

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

debug:
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF) $(LIBFT) -o $(NAME) -g3 -fsanitize=address