NAME := philo

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := srcs/*.c

all: $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

fclean : clean
	rm -rf $(NAME)

clean :

re: fclean all

.PHONY: all clean fclean re

debug:
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME) -g3 -fsanitize=address