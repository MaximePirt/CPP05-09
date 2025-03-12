SRC_FILES = main.cpp Base.cpp A.cpp B.cpp C.cpp

SRCDIR =
OBJ_D = objs
OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ_D)/%.o)
CC = c++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98

NAME = identifier
RM = rm -rf

DEFCOLOR = \033[0;39m
GREEN    = \033[1;92m
YELLOW   = \033[0;93m
PURPLE   = \033[0;95m
CYAN     = \033[0;96m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created successfully.$(DEFCOLOR)"

$(OBJ_D)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $< $(DEFCOLOR)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_D)
	@echo "$(PURPLE)Object files have been removed.$(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) has been removed.$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)$(NAME) was remake successfully $(DEFCOLOR)"

.PHONY: all clean fclean re