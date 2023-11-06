NAME		= libftprintf.a
LIBFT		= libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
SRC 		=	ft_put.c ft_printf.c ft_find.c
OBJ 		= 	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	ar rc $(NAME) *.o

all:		${NAME}

clean:
			@$(RM) -rf $(OBJ)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a

re:			fclean all