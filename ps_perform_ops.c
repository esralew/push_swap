
// 42 HEADER

//REMOVE BELOW
#include <stdio.h>

#include "push_swap.h"

void    perform_ops(t_list *ops, t_list **stack_a, t_list **stack_b)
{
    t_list  *curr;

    curr = ops;
    while (1)
    {
        if (check_ra(curr))
            rot(stack_a);
        else if (check_rra(curr))
            rrot(stack_a);
        else if (check_rb(curr))
            rot(stack_b);
        else if (check_rrb(curr))
            rrot(stack_b);
        else
            pb(stack_a, stack_b);
        if (!(curr->next))
            break;
        curr = curr->next;
    }
}