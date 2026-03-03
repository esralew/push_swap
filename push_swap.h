
// 42 HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"

t_list   *str_to_list(char *input_str);
//int get_n(char *input_str);
void    rot(t_list **stack);
void    rrot(t_list **stack);
void    rotrot(t_list **stack_a, t_list **stack_b);
void    rrotrrot(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);

#endif