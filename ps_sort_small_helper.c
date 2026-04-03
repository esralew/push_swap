/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:44:10 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 14:44:11 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_to_top(t_list **stack_a)
{
	t_list	*min;
	int		req_rot;
	int		req_rrot;

	min = find_min(*stack_a);
	req_rot = get_req_rot(min, stack_a);
	req_rrot = get_req_rrot(min, stack_a);
	if (req_rot <= req_rrot)
	{
		while (req_rot--)
		{
			rot(stack_a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (req_rrot--)
		{
			rrot(stack_a);
			ft_printf("rra\n");
		}
	}
}

t_list	*find_min(t_list *stack)
{
	t_list	*curr;
	t_list	*min;
	int		min_val;

	curr = stack;
	min_val = *(int *)curr->content;
	min = curr;
	if (ft_lstsize(stack) < 2)
		return (min);
	curr = curr->next;
	while (1)
	{
		if (*(int *)curr->content < min_val)
		{
			min_val = *(int *)curr->content;
			min = curr;
		}
		if (!(curr->next))
			break ;
		curr = curr->next;
	}
	return (min);
}
