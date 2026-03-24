
// 42 HEADER

#include "push_swap.h"

// we leave the dummy node from get_ops_a() in comm_lst, so if there is only
// one node in comm_lst, that means there aren't any operations inside comm_lst
// and we return the comm_lst unchanged
// -> prevention of dereferencing NULL
t_list  *opt_comm_lst(t_list **comm_lst)
{
    t_list  *p1;
    t_list  *p2;
    char    *new_comm;

    p1 = *comm_lst;
    p2 = *comm_lst;
    if (ft_lstsize(*comm_lst) == 1)
        return (*comm_lst);
    if (check_b_op(p1) || check_a_op(ft_lstlast(*comm_lst)))
        return (*comm_lst);
    while (check_a_op(p2->next))
        p2 = p2->next;
    if (ft_strlen((char *) p1->content) != (ft_strlen((char *) p2->content)))
        return (*comm_lst);
    while (p2->next)
    {
        if (check_ra(p1))
        {
            new_comm = ft_strdup("rr");
            if (!new_comm)
                return (NULL);
            free(p1->content);
            p1->content = new_comm; 
        }
        if (check_rra(p1))
        {
            new_comm = ft_strdup("rrr");
            if (!new_comm)
                return (NULL);
            free(p1->content);
            p1->content = new_comm; 
        }
        ft_lstdel_back(comm_lst, free);
        if (p1 == p2)
            break;
        p1 = p1->next;
    }
    return (*comm_lst);
    
////////////////////////////////////////////////FÜR WEITERE PLANUNG SIEHE SKIZZE    
} 

int check_a_op(t_list *node)
{
    if (check_ra(node) || check_rra(node))
        return (1);
    else 
        return (0);
}

int check_b_op(t_list *node)
{
    if (check_rb(node) || check_rrb(node))
        return (1);
    else 
        return (0);
}

int check_ra(t_list *node)
{
    char    *cont;

    cont = (char *) node->content;
    if (ft_strncmp(cont, "ra", 3) == 0)
        return (1);
    else 
        return (0);
}

int check_rra(t_list *node)
{
    char    *cont;

    cont = (char *) node->content;
    if (ft_strncmp(cont, "rra", 3) == 0)
        return (1);
    else 
        return (0);
}

int check_rb(t_list *node)
{
    char    *cont;

    cont = (char *) node->content;
    if (ft_strncmp(cont, "rb", 3) == 0)
        return (1);
    else 
        return (0);
}

int check_rrb(t_list *node)
{
    char    *cont;

    cont = (char *) node->content;
    if (ft_strncmp(cont, "rrb", 3) == 0)
        return (1);
    else 
        return (0);
}