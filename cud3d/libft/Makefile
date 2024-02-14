B = $(shell tput bold)
VERT = $(shell tput setaf 2)
BLEU = $(shell tput setaf 4)
D = $(shell tput sgr0)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = libft.h
SRCS = $(wildcard *.c) # Assure-toi que cela pointe vers tes fichiers .c
BUILDDIR = build/
OBJS = $(patsubst %.c,$(BUILDDIR)%.o,$(SRCS))

# Total number of source files
TOTAL_FILES = $(words $(SRCS))

# Counter for progress
COUNT = 0

# Function to update the progress bar
define update_progress
    @$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
    @printf "\r$(B)Compiling $(NAME): ["
    @i=0; while [[ $$i -lt $(COUNT) ]]; do printf "$(VERT)█$(D)"; ((i = i + 1)); done
    @i=$(COUNT); while [[ $$i -lt $(TOTAL_FILES) ]]; do printf " "; ((i = i + 1)); done
    @percentage=$$(( 100 * $(COUNT) / $(TOTAL_FILES) )); \
    printf "] %d%%" "$$percentage"
endef

.SILENT:

$(BUILDDIR)%.o: %.c
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@
	@$(call update_progress)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@printf "\n$(B)$(BLEU) -------------- $(NAME) compiled successfully --------------$(D)\n\n"

all: $(NAME)

clean:
	@echo "\n\033[1;31mCleaning $(NAME) \033[1m"
	rm -f $(OBJS)

fclean: 
	@echo "\n\033[1;31mDeep cleaning $(NAME) \033[1m"
	rm -f $(NAME) $(OBJS)

re: fclean all