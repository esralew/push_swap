
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
    t_list  *b_list;
    int cost_a;
    int cost_sync;
    int cost_opp;
    int req_rot_b;
    int req_rrot_b;
    char    *command;
    int iter;
    
    ///////////////////////////////////////////////////NORMINETTE + SEG FAULT
    cost_a = calc_cost_a(node, stack_a, &flag);
    req_rot_b = get_req_rot(find_succ(node, stack_b), stack_b);
    req_rrot_b = get_req_rrot(find_succ(node, stack_b), stack_b);
    cost_sync = calc_cost_sync(flag, cost_a, req_rot_b, req_rrot_b);
    cost_opp = calc_cost_opp(flag, req_rot_b, req_rrot_b);
    if (((!flag) && (cost_sync <= cost_opp)) || ((flag) && (cost_sync > cost_opp))) 
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
    b_list = build_list(command, iter);
    if (!b_list)
         return (free(command), NULL);
    return (free(command), b_list);
}

// having the nodes of the list contain COPIES of the command string is important, because if 
// they all point to the same string in memory, then a ft_lstclear(..., free) would call double-frees
static t_list   *build_list(char *command, int iter)
{
    t_list  *new;
    t_list  *b_list;
    char  *command_cpy;

    b_list = insert_dummy();
    if (!b_list)
        return (NULL);
    while (iter > 0)
    {
        command_cpy = ft_strdup(command);
        if (!command_cpy)
            return (ft_lstclear(&b_list, free), NULL);
        new = ft_lstnew(command_cpy);
        if (!new)
            return (ft_lstclear(&b_list, free),free(command_cpy), NULL);
        ft_lstadd_back(&b_list, new);
        iter--;
    }
    return (b_list);
}

// function to add a dummy node, that will be added by get_ops_a and get_ops_b, in case that no regular node had to be added (NULL return not possible, 
// because possibility to distinguish allocation fails is necessary)
t_list  *insert_dummy(void)
{
    t_list  *dummy;
    char    *dummy_str;
    
    dummy_str = ft_strdup("dummy");
    if (!dummy_str)
        return (NULL);
    dummy = ft_lstnew(dummy_str);
    if (!dummy)
        return (free(dummy_str), NULL);
    return (dummy);
}

void    ft_lstdel_front(t_list **lst, void (*del)(void *))
{
    t_list  *tmp;

    if (!lst || !(*lst))
        return; 
    tmp = *lst;
    *lst = (*lst)->next;
    ft_lstdelone(tmp, del);
}