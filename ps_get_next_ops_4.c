
// 42 HEADER

#include "push_swap.h"

static t_list   *build_list(char *command, int iter);

// t_list  *get_ops_b(t_list *node,t_list **stack_a, t_list **stack_b, int flag)
// {
//     t_list  *node;
//     t_list  *command_list;
//     int cost_a;
//     int cost_b;
//     int cost_sync;
//     int cost_opp;
//     int req_rot_b;
//     int req_rrot_b;
    
//     command_list = NULL;
//     cost_a = calc_cost_a(node, stack_a, &flag);
//     ///////////////////////////////////////////////////
    
//     req_rot_b = get_req_rot(node, stack_b);
//     req_rrot_b = get_req_rrot(node, stack_b);
//     cost_sync = calc_cost_sync(flag, cost_a, req_rot_b, req_rrot_b);
//     cost_opp = calc_cost_opp(flag, req_rot_b, req_rrot_b);
//     while (cost_b > 0)
//     {
//         node = build_correct_node(flag, cost_sync, cost_opp);
//         if (!node)
//             return (ft_lstclear(command_list, free), NULL);
//         ft_lstadd_back(&command_list, node);
//         cost_b--;
//     }
//     return (command_list);
// }

t_list  *get_ops_b(t_list *node,t_list **stack_a, t_list **stack_b, int flag)
{
    t_list  *command_list;
    int cost_a;
    int cost_b;
    int cost_sync;
    int cost_opp;
    int req_rot_b;
    int req_rrot_b;
    char    *command;
    int iter;
    
    ///////////////////////////////////////////////////NORMINETTE
    cost_a = calc_cost_a(node, stack_a, &flag);
    req_rot_b = get_req_rot(node, stack_b);
    req_rrot_b = get_req_rrot(node, stack_b);
    cost_sync = calc_cost_sync(flag, cost_a, req_rot_b, req_rrot_b);
    cost_opp = calc_cost_opp(flag, req_rot_b, req_rrot_b);
    if ((!flag) && (cost_sync <= cost_opp) || ((flag) && (cost_sync > cost_opp))) 
    {
        iter = req_rot_b;
        command = ft_strdup("rb");
    }
    else
    {
        iter = req_rrot_b;
        command = ft_strdup("rrb");
    }
    if (!command)
        return (NULL);
    command_list = build_list(command, iter);
    if (!command_list)
        return (free(command), NULL);
    return (command_list);
}

static t_list   *build_list(char *command, int iter)
{
    t_list  *node;
    t_list  *command_list;

    command_list = NULL;
    while (iter > 0)
    {
        node = ft_lstnew(command);
        if (!node)
            return (ft_lstclear(command_list, free), NULL);
        ft_lstadd_back(&command_list, node);
        iter--;
    }
    return (command_list);
}