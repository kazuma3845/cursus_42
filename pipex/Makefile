NAME := pipex

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := srcs/*.c libft/libft.a

all: $(NAME)
	

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

clean :
	rm -rf $(NAME)
	make clean -C libft

re: fclean all

.PHONY: all clean fclean re

debug:
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME) -g3 -fsanitize=address