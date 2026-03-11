
// 42 HEADER

#include "push_swap.h"

int get_req_rot(t_list *node, t_list **stack)
{
    int req_rot;
    t_list *current;

    req_rot = 0;
    current = *stack;
    if (current == node)
        return (0);
    while  (!((current->next) == node))
    {
        req_rot++;
        current = current->next;
    }
    return (req_rot + 1);
}

int get_req_rrot(t_list *node, t_list **stack)
{
    if (node == (*stack))
        return (0);
    return (ft_lstsize(node));
}

int calc_cost_sync(int flag,int cost_a,int req_rot_b,int req_rrot_b)
{
    int cost_sync;

    if (!flag)
        cost_sync = req_rot_b - cost_a;
    else    
        cost_sync = req_rrot_b - cost_a;
    if (cost_sync <= 0)
        return (0);
    else 
        return (cost_sync);
}

int calc_cost_opp(int flag, int req_rot_b,int req_rrot_b)
{
    int cost_opp;
    
    if (!flag)
        cost_opp = req_rrot_b;
    else    
        cost_opp = req_rot_b;
    return (cost_opp);
}

int abs(int x)
{
    if (x < 0)
        return (-x);
    return (x);
}