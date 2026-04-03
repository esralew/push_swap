/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_ops_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:33:12 by elewin            #+#    #+#             */
/*   Updated: 2026/04/01 18:33:22 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*build_list(char *command, int iter);
static t_list	*get_b_list(int flag, int cost_sync, int req_rot_b,
					int req_rrot_b);

t_list	*get_ops_b(t_list *next_elem, t_list **stack_a, t_list **stack_b,
		int flag)
{
	t_list	*b_list;
	int		cost_a;
	int		cost_sync;
	int		req_rot_b;
	int		req_rrot_b;

	cost_a = calc_cost_a(next_elem, stack_a, &flag);
	req_rot_b = get_req_rot(find_succ(next_elem, stack_b), stack_b);
	req_rrot_b = get_req_rrot(find_succ(next_elem, stack_b), stack_b);
	cost_sync = calc_cost_sync(flag, cost_a, req_rot_b, req_rrot_b);
	b_list = get_b_list(flag, cost_sync, req_rot_b, req_rrot_b);
	if (!b_list)
		return (NULL);
	return (b_list);
}

static t_list	*get_b_list(int flag, int cost_sync, int req_rot_b,
		int req_rrot_b)
{
	char	*command;
	int		iter;
	int		cost_opp;
	t_list	*b_list;

	cost_opp = calc_cost_opp(flag, req_rot_b, req_rrot_b);
	if (((!flag) && (cost_sync <= cost_opp)) || ((flag)
			&& (cost_sync > cost_opp)))
	{
		iter = req_rot_b;
		command = ft_strdup("rb");
	}
	else
	{
		iter = req_rrot_b;
		command = ft_strdup("rrb");
	}
	if (!command)
		return (NULL);
	b_list = build_list(command, iter);
	if (!b_list)
		return (free(command), NULL);
	return (free(command), b_list);
}

// having the nodes of the list contain COPIES of the command string is
// important, because if
// they all point to the same string in memory, then a ft_lstclear(...,
// free) would call double-frees
static t_list	*build_list(char *command, int iter)
{
	t_list	*new;
	t_list	*b_list;
	char	*command_dup;

	b_list = insert_dummy();
	if (!b_list)
		return (NULL);
	while (iter > 0)
	{
		command_dup = ft_strdup(command);
		if (!command_dup)
			return (ft_lstclear(&b_list, free), NULL);
		new = ft_lstnew(command_dup);
		if (!new)
			return (ft_lstclear(&b_list, free), free(command_dup), NULL);
		ft_lstadd_back(&b_list, new);
		iter--;
	}
	return (b_list);
}
