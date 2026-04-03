NAME = push_swap

# 20 source files
SRC = ps_main.c\
ps_main_helper.c\
ps_get_next_elem.c\
ps_perform_ops_1.c\
ps_perform_ops_2.c\
ps_stack_ops_1.c\
ps_stack_ops_2.c\
ft_strtol.c\
ps_calc_cost_1.c\
ps_calc_cost_2.c\
ps_print_ops.c\
ps_opt_comm_lst.c\
ps_sort_3_desc.c\
ps_str_to_list.c\
ps_check_input.c\
ps_sort_small.c\
ps_sort_small_helper.c\
ps_get_ops_1.c\
ps_get_ops_2.c\
ps_get_ops_helper.c

OBJ = $(SRC:.c=.o) 
CFLAGS = -Wall -Wextra -Werror -g -O0
CC = cc 
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libftprintf.a
INCLUDES = -I./includes -I$(LIBFT_DIR)

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean: 
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
