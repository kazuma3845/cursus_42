NAME = webserv
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS = $(shell find srcs -name '*.cpp')
OBJS = $(SRCS:srcs/%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR = objects

all: $(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@echo "\033[0;32mCompilation finished\033[0m"


$(OBJ_DIR)/%.o: srcs/%.cpp | create_dirs
		@$(CC) $(CFLAGS) -c $< -o $@

create_dirs:
		@mkdir -p $(dir $(OBJS))

clean:
		@rm -rf $(OBJS)
		@echo "\033[0;31mClean files\033[0m"

fclean:
		@rm -rf $(OBJS)
		@rm -rf $(NAME)
		@rm -rf $(OBJ_DIR)
		@echo "\033[0;31mClean all files\033[0m"

re: fclean all
