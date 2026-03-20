
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

t_list  *get_ops(t_list *node, t_list **stack_a, t_list **stack_b)
{
    t_list  *command_list;
    t_list  *b_list;
    t_list  *push;
    int flag;

    flag = 0;
    //////////////////////////////
    command_list = get_ops_a(node, stack_a, &flag);
    if (!command_list)
        return (NULL);
    ft_lstdel_front(&command_list, free);
    b_list = get_ops_b(node, stack_a, stack_b, flag);
    if (!b_list)
        return (ft_lstclear(&command_list, free), NULL);
    ft_lstdel_front(&b_list, free);
    ft_lstadd_back(&command_list, b_list);
    // optimize_command_list(&command_list, node, stack_a, stack_b);
    push = ft_lstnew("pb");
    if (!push)
        return (ft_lstclear(&command_list, free), NULL);
    ft_lstadd_back(&command_list, push);
    return (command_list);
    //////////////////////////////////
}

// if flag is still 0 after call of calc_cost_a, then we do normal rotations 
// Purpose of command_cpy: see function build_list() in ps_get_next_ops_4.c
t_list  *get_ops_a(t_list *node, t_list **stack_a, int *flag)
{
    t_list  *next;
    t_list  *command_list;
    int cost_a;
    char    *command;
    char    *command_cpy;
    
    command_list = insert_dummy();
    if (!command_list)
        return (NULL);
    cost_a = calc_cost_a(node, stack_a, flag);
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
        next = ft_lstnew(command_cpy);
        if (!next)
            return (ft_lstclear(&command_list, free), free(command), NULL);
        ft_lstadd_back(&command_list, next);
        cost_a--;
    }
    return (command_list);
}

void    optimize_command_list(t_list **command_list, t_list *node, t_list **stack_a, t_list **stack_b)
{
    t_list  *curr;
    int num_ops_a;
    int num_ops_b;

    curr = *command_list;
    while (curr->next)
    {
        if (*(char *) curr->content == "ra" || *(char *) curr->content == "rra")
            num_ops_a++;
        else
            num_ops_b++;
        curr = curr->next;
    }
    if (*(char *) curr->content == "ra" || *(char *) curr->content == "rra")
        num_ops_a++;
    else
        num_ops_b++;
    
        ///////////////////////////////////////
}