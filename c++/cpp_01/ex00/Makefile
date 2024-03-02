B = $(shell tput bold)
VERT = $(shell tput setaf 2)
BLEU = $(shell tput setaf 4)
D = $(shell tput sgr0)

NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./include
BUILDDIR = build/

SRCS = $(shell find srcs -name '*.cpp')
OBJS = $(patsubst srcs/%.cpp,$(BUILDDIR)%.o,$(SRCS))
INCLUDES = -I./include

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

all: $(NAME)
	@printf "\n$(B)$(BLEU) ---- $(NAME) compiled successfully ----$(D)\n\n"

$(BUILDDIR)%.o: srcs/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -cpp $< -o $@
	@$(call update_progress)


$(NAME):
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "Cleaning $(NAME)\n"
	@rm -rf $(BUILDDIR)

fclean:
	@echo "Deep cleaning $(NAME)\n"
	@rm -rf $(BUILDDIR) $(NAME)

re: fclean all
