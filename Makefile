NAME = push_swap
SRC = push_swap.c ps_str_to_list.c ps_stack_ops.c ps_stack_ops_2.c\
ps_get_next_ops.c ps_get_next_ops_2.c ps_get_next_ops_3.c ps_get_next_ops_4.c\
ps_get_next_ops_5.c ps_print_ops.c
OBJ = $(SRC:.c=.o) 
CFLAGS = -Wall -Wextra -Werror -g -O0
CC = cc 
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I./includes -I$(LIBFT_DIR)

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean: 
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all



