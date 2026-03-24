
// 42 HEADER

#include "push_swap.h"

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
    while (curr->next)
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

t_list  *get_ops(t_list *next_elem, t_list **stack_a, t_list **stack_b)
{
    t_list  *comm_lst;
    t_list  *fin_comm_lst;
    t_list  *b_list;
    t_list  *push;
    int flag;
    char    *pb;

    flag = 0;
    //////////////////////////////
    comm_lst = get_ops_a(next_elem, stack_a, &flag);
    if (!comm_lst)
        return (NULL);
    b_list = get_ops_b(next_elem, stack_a, stack_b, flag);
    if (!b_list)
        return (ft_lstclear(&comm_lst, free), NULL);
    ft_lstdel_front(&b_list, free);
    ft_lstadd_back(&comm_lst, b_list);
    fin_comm_lst = opt_comm_lst(&comm_lst);
    if (!fin_comm_lst)
        return (ft_lstclear(&comm_lst, free), NULL);
    ft_lstdel_front(&comm_lst, free);
    pb = ft_strdup ("pb");
    if (!pb)
        return (ft_lstclear(&fin_comm_lst, free), NULL);
    push = ft_lstnew(pb);
    if (!push)
        return (ft_lstclear(&fin_comm_lst, free), NULL);
    ft_lstadd_back(&fin_comm_lst, push);
    return (fin_comm_lst);
    //////////////////////////////////
}

// if flag is still 0 after call of calc_cost_a, then we do normal rotations 
// Purpose of command_cpy: see function build_list() in ps_get_next_ops_4.c
t_list  *get_ops_a(t_list *next_elem, t_list **stack_a, int *flag)
{
    t_list  *new;
    t_list  *command_list;
    int cost_a;
    char    *command;
    char    *command_cpy;
    
    command_list = insert_dummy();
    if (!command_list)
        return (NULL);
    cost_a = calc_cost_a(next_elem, stack_a, flag);
    if (!(*flag))
        command = ft_strdup("ra");
    else
        command = ft_strdup("rra");
    if (!command)
        return (ft_lstclear(&command_list, free), NULL);
    while (cost_a > 0)
    {
    // in case of norminette problems we can substitute with static function build_list() from other file here
        command_cpy = ft_strdup(command);
        if (!command_cpy)
            return (ft_lstclear(&command_list, free), NULL);
        new = ft_lstnew(command_cpy);
        if (!new)
            return (ft_lstclear(&command_list, free), free(command), NULL);
        ft_lstadd_back(&command_list, new);
        cost_a--;
    }
    return (free(command), command_list);
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

void    ft_lstdel_back(t_list **lst, void (*del)(void *))
{
    t_list  *tmp;

    if (!lst || !(*lst))
        return; 
    tmp = ft_lst_scndlast(*lst);
    ft_lstdelone(tmp->next, del);
    tmp->next = NULL;

}