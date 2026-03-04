
// 42 HEADER

#include "push_swap.h"

static t_list	*ft_lst_scndlast(t_list *lst);

void    rot(t_list **stack)
{
    t_list  *first;

    if (ft_lstsize(*stack) < 2)
        return;
    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;
    ft_lstadd_back(stack, first);
}

void    rotrot(t_list **stack_a, t_list **stack_b)
{
    rot(stack_a);
    rot(stack_b);
}

void    rrot(t_list **stack)
{
    t_list  *last;
    t_list  *scnd_last;

    if (ft_lstsize(*stack) < 2)
        return;
    last = ft_lstlast(*stack);
    scnd_last = ft_lst_scndlast(*stack);
    scnd_last->next = NULL;
    ft_lstadd_front(stack, last);
}

void    rrotrrot(t_list **stack_a, t_list **stack_b)
{
    rrot(stack_a);
    rrot(stack_b);
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