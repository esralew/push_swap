
// 42 HEADER

#include "push_swap.h"

// if flag gets set to 1, then the next element in stack a will be moved through rotations (upwards travel)
// if flag stays set to 0, then the next element will be moved through reverse rotations (downwards travel) 
t_list *get_next_ops(t_list **stack_a, t_list **stack_b)
{
    t_list  *current;
    t_list  *next_elem;
    t_list  *first;
    int min_cost;

    current = NULL;
    first = *stack_a;
    // wenn zuviele lines, dann hier workaround mit min_cost = INT_MAX
    min_cost = calc_cost(first, stack_a, stack_b);
    next_elem = first;
    if (first->next)
        current = first->next;
    while ((current)->next)
    {
        if (calc_cost(current, stack_a, stack_b) < min_cost)
        {
            min_cost = calc_cost(current, stack_a, stack_b);
            next_elem = current;
        }
        current = current->next;
    }
    return (store_ops(next_elem));
}

int calc_cost(t_list *node, t_list **stack_a, t_list **stack_b)
{
    int cost_a;
    int cost_b;
    int flag;

    cost_a = calc_cost_a(node, stack_a, &flag);
    flag = 0;
    cost_b = calc_cost_b(node, stack_b, flag, cost_a);
    return (cost_a + cost_b);
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
    cost_opp = calc_cost_opp(flag, cost_a, req_rot_b, req_rrot_b);
    if (cost_sync <= cost_opp)
        return (cost_sync);
    else
        return (cost_opp);
}

t_list  *find_succ(t_list *node, t_list **stack_b)
{
    t_list  *succ;
    t_list  *curr;
    int val_node;
    int val_curr;
    int closest;
    int diff;

    val_node = *((int *) (node->content));
    val_curr = *((int *) (curr->content));
    curr = *stack_b;
    succ = NULL;
    while ((curr->next) && (val_curr > val_node))
        curr = curr->next;
    diff = abs(val_node - val_curr);
    closest = diff;
    succ = curr;
    while (curr->next)
    {
        if ((val_curr < val_node) && diff < closest)
        {
            closest = diff;
            succ = curr;
        }
        curr = curr->next;
    }
    return (succ);
}
