NAME = Sed_is_for_losers
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[0;32mCompilation finished\033[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "\033[0;31mClean files\033[0m"

fclean:	
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm *.replace
	@echo "\033[0;31mClean all files\033[0m"

re: fclean all
