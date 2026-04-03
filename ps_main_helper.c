/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:41:34 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 17:43:57 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_all(t_list **stack_a, t_list **stack_b)
{
	int	n;

	n = ft_lstsize(*stack_b);
	while (n > 0)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
		n--;
	}
}

void	max_to_top(t_list **stack_b)
{
	t_list	*max;
	int		req_rot;
	int		req_rrot;

	max = find_max(*stack_b);
	req_rot = get_req_rot(max, stack_b);
	req_rrot = get_req_rrot(max, stack_b);
	if (req_rot <= req_rrot)
	{
		while (req_rot--)
		{
			rot(stack_b);
			ft_printf("rb\n");
		}
	}
	else
	{
		while (req_rrot--)
		{
			rrot(stack_b);
			ft_printf("rrb\n");
		}
	}
}

void	push_3(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	ft_printf("pb\n");
	ft_printf("pb\n");
}
