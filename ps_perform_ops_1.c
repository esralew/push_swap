/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_perform_ops_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:36:41 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 14:52:05 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_ops(t_list *ops, t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;

	curr = ops;
	while (1)
	{
		if (check_ra(curr))
			rot(stack_a);
		else if (check_rra(curr))
			rrot(stack_a);
		else if (check_rb(curr))
			rot(stack_b);
		else if (check_rrb(curr))
			rrot(stack_b);
		else if (check_rr(curr))
			rotrot(stack_a, stack_b);
		else if (check_rrr(curr))
			rrotrrot(stack_a, stack_b);
		else
			pb(stack_a, stack_b);
		if (!(curr->next))
			break ;
		curr = curr->next;
	}
}

int	check_ra(t_list *node)
{
	char	*cont;

	cont = (char *)node->content;
	if (ft_strncmp(cont, "ra", 3) == 0)
		return (1);
	else
		return (0);
}
