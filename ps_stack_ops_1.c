/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_ops_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:37:12 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 14:52:26 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot(t_list **stack)
{
	t_list	*first;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

void	rotrot(t_list **stack_a, t_list **stack_b)
{
	rot(stack_a);
	rot(stack_b);
}

void	rrot(t_list **stack)
{
	t_list	*last;
	t_list	*scnd_last;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	scnd_last = ft_lst_scndlast(*stack);
	scnd_last->next = NULL;
	ft_lstadd_front(stack, last);
}

void	rrotrrot(t_list **stack_a, t_list **stack_b)
{
	rrot(stack_a);
	rrot(stack_b);
}

t_list	*ft_lst_scndlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while ((current->next)->next)
		current = current->next;
	return (current);
}
