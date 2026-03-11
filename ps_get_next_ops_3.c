
// 42 HEADER

#include "push_swap.h"

t_list  *find_max(t_list *stack)
{
    t_list *curr;
    t_list  *max;
    int max_val;

    curr = stack;
    max_val = *(int *) curr->content;
    max = curr;
    if (ft_lstsize(stack) < 2)
        return (max);
    curr = curr->next;
    while (1)
    {
        if (*(int *) curr->content > max_val)
        {
            max_val = *(int *) curr->content;
            max = curr;
        }
        if (!(curr->next))
            break;
        curr = curr->next;
    }
    return (max);
}

t_list  *get_next_elem(t_list **stack_a, t_list **stack_b)
{
    t_list  *curr;
    t_list  *first;
    t_list  *next_elem;
    int min_cost;

    curr = NULL;
    first = *stack_a;
    // wenn zuviele lines, dann hier workaround mit min_cost = INT_MAX
    min_cost = calc_cost(first, stack_a, stack_b);
    next_elem = first;
    if (first->next)
        curr = first->next;
    while ((curr)->next)
    {
        if (calc_cost(curr, stack_a, stack_b) < min_cost)
        {
            min_cost = calc_cost(curr, stack_a, stack_b);
            next_elem = curr;
        }
        curr = curr->next;
    }
    if (calc_cost(curr, stack_a, stack_b) < min_cost)
        next_elem = curr;
    return (next_elem);
}

t_list  *get_ops(t_list *node, t_list **stack_a, t_list **stack_b)
{
    //
}