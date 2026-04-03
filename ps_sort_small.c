/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:05:16 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 14:43:29 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_asc(t_list **stack);
static void	sort_5_asc(t_list **stack_a, t_list **stack_b);
static void	sort_3_asc_dec_tree(int top, int mid, int bot, t_list **stack);
static void	decide_mid_larger_bot(int top, int mid, int bot, t_list **stack);

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
		sort_3_asc(stack_a);
	else if (size == 4)
	{
		min_to_top(stack_a);
		pb(stack_a, stack_b);
		ft_printf("pb\n");
		sort_3_asc(stack_a);
		pa(stack_a, stack_b);
		ft_printf("pa\n");
	}
	else
		sort_5_asc(stack_a, stack_b);
}

static void	sort_3_asc(t_list **stack)
{
	int	top;
	int	mid;
	int	bot;

	if (ft_lstsize(*stack) == 1)
		return ;
	top = *(int *)(*stack)->content;
	mid = *(int *)(*stack)->next->content;
	if (ft_lstsize(*stack) == 2)
	{
		if (top > mid)
		{
			ft_printf("ra\n");
			return (rot(stack));
		}
		else
			return ;
	}
	bot = *(int *)(*stack)->next->next->content;
	sort_3_asc_dec_tree(top, mid, bot, stack);
}

static void	sort_5_asc(t_list **stack_a, t_list **stack_b)
{
	min_to_top(stack_a);
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	min_to_top(stack_a);
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	sort_3_asc(stack_a);
	pa(stack_a, stack_b);
	ft_printf("pa\n");
	pa(stack_a, stack_b);
	ft_printf("pa\n");
}

static void	sort_3_asc_dec_tree(int top, int mid, int bot, t_list **stack)
{
	if (top < mid)
		decide_mid_larger_bot(top, mid, bot, stack);
	else
	{
		if (top < bot)
		{
			ft_printf("sa\n");
			return (switcheroo(stack));
		}
		rot(stack);
		ft_printf("ra\n");
		if (bot < mid)
		{
			switcheroo(stack);
			ft_printf("sa\n");
		}
	}
}

static void	decide_mid_larger_bot(int top, int mid, int bot, t_list **stack)
{
	if (mid < bot)
		return ;
	rrot(stack);
	ft_printf("rra\n");
	if (top < bot)
	{
		switcheroo(stack);
		ft_printf("sa\n");
	}
}
