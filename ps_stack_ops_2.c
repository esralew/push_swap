
// 42 HEADER

#include "push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *top_b;

    if (ft_lstsize(*stack_b) < 1)
        return;
    top_b = *stack_b;
    *stack_b = (*stack_b)->next;
    ft_lstadd_front(stack_a, top_b);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *top_a;

    if (ft_lstsize(*stack_a) < 1)
        return;
    top_a = *stack_a;
    *stack_a = (*stack_a)->next;
    ft_lstadd_front(stack_b, top_a);
}

void    switcheroo(t_list **stack)
{
    t_list  *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}