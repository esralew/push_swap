/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_next_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:36:07 by elewin            #+#    #+#             */
/*   Updated: 2026/04/01 18:40:57 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_next_elem(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*next_elem;
	int		min_cost;

	curr = *stack_a;
	next_elem = curr;
	min_cost = calc_cost(curr, stack_a, stack_b);
	if (!(curr->next))
		return (curr);
	while (1)
	{
		if (calc_cost(curr, stack_a, stack_b) < min_cost)
		{
			min_cost = calc_cost(curr, stack_a, stack_b);
			next_elem = curr;
		}
		if (!(curr->next))
			break ;
		curr = curr->next;
	}
	return (next_elem);
}
