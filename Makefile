CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./include -I ./libft
SRC_DIR = src
CFILES = main.c cracked_atoi.c operations.c error_handler.c parser.c solver.c bubble_sort.c radix.c
OBJ_DIR = $(SRC_DIR)/obj
OBJ = $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o)) 
NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT)  -o $@

$(LIBFT): $(LIBFT_DIR)
	make -C $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR): 
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
