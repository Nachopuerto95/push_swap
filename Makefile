NAME = push_swap
CHECKER_NAME = checker

SRC = main.c src/throw_error.c sort_utils.c stack_init.c push_swap.c src/ft_split.c src/ft_lstsize.c src/lst_utils.c src/instruction/push.c src/instruction/swap.c src/instruction/rotate.c src/instruction/rev_rotate.c src/init_nodes_b.c src/ft_strchr.c
BONUS_SRC = src/get_next_line.c checker.c sort_utils.c stack_init.c push_swap.c src/ft_split.c src/ft_lstsize.c src/lst_utils.c src/instruction/push.c src/instruction/swap.c src/instruction/rotate.c src/instruction/rev_rotate.c src/init_nodes_b.c src/ft_strchr.c src/throw_error.c checker_utils.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

HEADER = includes/push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(CHECKER_NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)/*
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
