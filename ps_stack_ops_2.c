
// 42 HEADER

#include "push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *top_b;

    top_b = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_front(stack_a, top_b);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *top_a;

    top_a = *stack_a;
    *stack_a = (*stack_a)->next;
    ft_lstadd_front(stack_b, top_a);
}