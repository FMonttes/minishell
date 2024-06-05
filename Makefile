NAME = minishell

CFLAGS = -Wall -Werror -Wextra
CC = cc -g
RM = rm -rf

SRC_DIR = src
BUILTINS_DIR = /builtins
REDIRECTS_DIR = /redirects
EXECUTOR_DIR = /executor
INCLUDES_DIR = /includes
UTILS_DIR = /utils
LIBFT = libft.a

SRCS = $(wildcard $(SRC_DIR)/*.c) \
       $(wildcard $(SRC_DIR)$(BUILTINS_DIR)/*.c) \
       $(wildcard $(SRC_DIR)$(REDIRECTS_DIR)/*.c) \
       $(wildcard $(SRC_DIR)$(EXECUTOR_DIR)/*.c) \
       $(wildcard $(SRC_DIR)$(UTILS_DIR)/*.c)
       $(wildcard $(SRC_DIR)$(INCLUDES_DIR)/*.h)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft > /dev/null
	@echo "Compilando..."
	@$(CC) $(CFLAGS) $(OBJS) libft/$(LIBFT) -o $(NAME) -lreadline > /dev/null
	@echo "\033[0;32mCompilation Finished\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  > /dev/null

clean:
	@make clean -C libft > /dev/null
	@$(RM) $(SRC_DIR)/*.o
	@$(RM) $(SRC_DIR)$(BUILTINS_DIR)/*.o
	@$(RM) $(SRC_DIR)$(REDIRECTS_DIR)/*.o
	@$(RM) $(SRC_DIR)$(EXECUTOR_DIR)/*.o
	@$(RM) $(SRC_DIR)$(UTILS_DIR)/*.o

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)
	@$(RM) libft/$(LIBFT)

re: fclean all
