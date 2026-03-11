
// 42 HEADER

#include "push_swap.h"

// if flag gets set to 1, then the next element in stack a will be moved through rotations (upwards travel)
// if flag stays set to 0, then the next element will be moved through reverse rotations (downwards travel) 
t_list *get_next_ops(t_list **stack_a, t_list **stack_b)
{
    t_list  *current;
    t_list  *next_elem;
    t_list  *ops;

    next_elem = get_next_elem(stack_a, stack_b);
    ops = get_ops(next_elem, stack_a, stack_b);
}

int calc_cost(t_list *node, t_list **stack_a, t_list **stack_b)
{
    int cost_a;
    int cost_b;
    int flag;

    flag = 0;
    cost_a = calc_cost_a(node, stack_a, &flag);
    cost_b = calc_cost_b(node, stack_b, flag, cost_a);
    return (cost_a + cost_b + 1);
}

int calc_cost_a(t_list *node, t_list **stack_a, int *flag)
{
    int req_rot_a;
    int req_rrot_a;

    req_rot_a = get_req_rot(node, stack_a);
    req_rrot_a = get_req_rrot(node, stack_a);
    if (req_rrot_a < req_rot_a)
    {
        *flag = 1;
        return (req_rrot_a);
    }
    else
        return (req_rot_a);
}

int calc_cost_b(t_list *node, t_list **stack_b, int flag, int cost_a)
{
    int req_rot_b;
    int req_rrot_b;
    int cost_sync;
    int cost_opp;
    t_list  *succ;

    succ = find_succ(node, stack_b);
    // if no succ was found, then node is the new min in b and can be placed on top
    if (!succ)
        return (0);
    req_rot_b = get_req_rot(succ, stack_b);
    req_rrot_b = get_req_rrot(succ, stack_b);
    cost_sync = calc_cost_sync(flag, cost_a, req_rot_b, req_rrot_b);
    cost_opp = calc_cost_opp(flag, req_rot_b, req_rrot_b);
    if (cost_sync <= cost_opp)
        return (cost_sync);
    else
        return (cost_opp);
}

t_list  *find_succ(t_list *node, t_list **stack_b)
{
    t_list  *succ;
    t_list  *curr;
    int val_curr;
    int val_node;
    int val_next;

    curr = *stack_b;
    // if no fit for node was found (node is new min or new max), we return the current max as successor
    succ = find_max(*stack_b);
    val_node = *((int *) (node->content));
    // check if node_value is between last element and top element -> if yes, return top element
    if ((*((int *) (curr->content)) < val_node) && (val_node < *(int *) ft_lstlast(*stack_b)->content))  
        return (curr);
    while (1)
    {
        val_curr = *((int *) (curr->content));
        val_next = *((int *) (curr->next->content));
        val_node = *((int *) (node->content));
        if (((val_next < val_node) && (val_node < val_curr)) || !(curr->next->next))
            break;
        curr = curr->next;
    }
    if ((val_next < val_node) && (val_node < val_curr))
        succ = curr->next;
    return (succ);
}
