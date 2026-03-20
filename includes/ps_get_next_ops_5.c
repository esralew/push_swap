
// 42 HEADER

#include "push_swap.h"

void    optimize_command_list(t_list **command_list, t_list *node, t_list **stack_a, t_list **stack_b)
{
    t_list  *p1;
    t_list  *p2;
    int num_ops_a;
    int num_ops_b;

    p1 = *command_list;
    p2 = *command_list;
    if (check_node_b_op(p1) || check_node_a_op(ft_lstlast(*command_list)))
        return;
    while (check_node_a_op(p2))
        p2 = p2->next;
    if ()
    while (!(check_node_b_op(p1)) && )
////////////////////////////////////////////////FÜR WEITERE PLANUNG SIEHE SKIZZE    
   
    // while (curr->next)
    // {
    //     if (*(char *) curr->content == "ra" || *(char *) curr->content == "rra")
    //         num_ops_a++;
    //     else
    //         num_ops_b++;
    //     curr = curr->next;
    // }
    // if (*(char *) curr->content == "ra" || *(char *) curr->content == "rra")
    //     num_ops_a++;
    // else
    //     num_ops_b++;
    
        ///////////////////////////////////////
} 

int check_node_a_op(t_list *node)
{
    char    *cont;

    cont = (char *) node->content;
    if (!(ft_strncmp(cont, "ra", 3)) || !(ft_strncmp(cont, "rra", 3)))
        return (1);
    else 
        return (0);
}

int check_node_b_op(t_list *node)
{
    char    *cont;

    cont = (char *) node->content;
    if (!(ft_strncmp(cont, "rb", 3)) || !(ft_strncmp(cont, "rrb", 3)))
        return (1);
    else 
        return (0);
}