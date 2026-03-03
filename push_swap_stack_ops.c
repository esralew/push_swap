
// 42 HEADER

#include "push_swap.h"

static t_list	*ft_lst_scndlast(t_list *lst);

void    ra(t_list **stack_a)
{
    t_list  *first;

    first = *stack_a;
    *stack_a = (*stack_a)->next;
    first->next = NULL;
    ft_lstadd_back(stack_a, first);
}

void    rra(t_list **stack_a)
{
    t_list  *last;
    t_list  *scnd_last;

    last = ft_lstlast(*stack_a);
    scnd_last = ft_lst_scndlast(*stack_a);
    scnd_last->next = NULL;
    ft_lstadd_front(stack_a, last);
}


static t_list	*ft_lst_scndlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while ((current->next)->next)
		current = current->next;
	return (current);
}