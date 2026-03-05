
// 42 HEADER

#include "push_swap.h"

void    perform_ops(storage ops)
{
    while (ops.num_pa)
    {
        //
    }
}

// if flag gets set to 1, then the next element in stack a will be moved through rotations (upwards travel)
// if flag stays set to 0, then the next element will be moved through reverse rotations (downwards travel) 
storage *get_next_ops(t_list **stack_a, t_list **stack_b)
{
    storage *ops;
    int cost_a;
    int cost_b;
    int flag;

    flag = 0;
    ops = (storage *) malloc(sizeof(storage));
    if (!ops)
        return (NULL);
    cost_a = calc_cost_a(stack_a, flag);
    cost_b = calc_cost_b(cost_a, stack_b, flag);
    
}