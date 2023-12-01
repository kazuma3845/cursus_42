NAME		= push_swap
CC			= GCC
CFLAGS		= -Wall -Wextra -Werror
HEADER		= push_swap.h

SRCS		= push_swap_utils-1.c push_swap_utils-2.c commands-1.c commands-2.c algo.c main.c error.c moves.c init_a.c init_b.c stack_init.c
OBJS		= ${SRCS:.c=.o}
LIBFT		= ./Libft/libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBFT}
	make -C ./libft
	${CC} ${CFLAGS} ${OBJS} -I ${HEADER} ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${OBJS}
	make clean -C ./libft

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
