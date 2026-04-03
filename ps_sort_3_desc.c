/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_3_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:36:59 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 13:00:57 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_desc_helper(int top, int mid, int bot, t_list **stack);
static void	decide_top_larger_mid(int top, int mid, int bot, t_list **stack);

void	sort_3_desc(t_list **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = *(int *)(*stack)->content;
	mid = *(int *)(*stack)->next->content;
	bot = *(int *)(*stack)->next->next->content;
	sort_3_desc_helper(top, mid, bot, stack);
}

static void	sort_3_desc_helper(int top, int mid, int bot, t_list **stack)
{
	if (top > mid)
		decide_top_larger_mid(top, mid, bot, stack);
	else
	{
		if (top > bot)
		{
			ft_printf("sb\n");
			return (switcheroo(stack));
		}
		rot(stack);
		ft_printf("rb\n");
		if (bot > mid)
		{
			switcheroo(stack);
			ft_printf("sb\n");
		}
	}
}

static void	decide_top_larger_mid(int top, int mid, int bot, t_list **stack)
{
	if (mid > bot)
		return ;
	rrot(stack);
	ft_printf("rrb\n");
	if (top > bot)
	{
		switcheroo(stack);
		ft_printf("sb\n");
	}
}
