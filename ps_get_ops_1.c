/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_ops_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:32:57 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 17:21:02 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ops_a_append_nodes(t_list *comm_lst, int cost_a, char *comm);
static t_list	*add_push(t_list *fin_comm_lst);

t_list	*get_ops(t_list *next_elem, t_list **stack_a, t_list **stack_b)
{
	t_list	*comm_lst;
	t_list	*fin_comm_lst;
	t_list	*b_list;
	int		flag;

	flag = 0;
	comm_lst = get_ops_a(next_elem, stack_a, &flag);
	if (!comm_lst)
		return (NULL);
	b_list = get_ops_b(next_elem, stack_a, stack_b, flag);
	if (!b_list)
		return (ft_lstclear(&comm_lst, free), NULL);
	ft_lstdel_front(&b_list, free);
	ft_lstadd_back(&comm_lst, b_list);
	fin_comm_lst = opt_comm_lst(&comm_lst);
	if (!fin_comm_lst)
		return (ft_lstclear(&comm_lst, free), NULL);
	ft_lstdel_front(&fin_comm_lst, free);
	fin_comm_lst = add_push(fin_comm_lst);
	if (!fin_comm_lst)
		return (NULL);
	return (fin_comm_lst);
}

static t_list	*add_push(t_list *fin_comm_lst)
{
	char	*pb;
	t_list	*push;

	pb = ft_strdup("pb");
	if (!pb)
		return (ft_lstclear(&fin_comm_lst, free), NULL);
	push = ft_lstnew(pb);
	if (!push)
		return (ft_lstclear(&fin_comm_lst, free), free(pb), NULL);
	ft_lstadd_back(&fin_comm_lst, push);
	return (fin_comm_lst);
}

// if flag is still 0 after call of calc_cost_a, then we do normal rotations
// Purpose of command_cpy: see function build_list() in ps_get_next_ops_4.c
t_list	*get_ops_a(t_list *next_elem, t_list **stack_a, int *flag)
{
	t_list	*comm_lst;
	int		cost_a;
	char	*comm;

	comm_lst = insert_dummy();
	if (!comm_lst)
		return (NULL);
	cost_a = calc_cost_a(next_elem, stack_a, flag);
	if (!(*flag))
		comm = ft_strdup("ra");
	else
		comm = ft_strdup("rra");
	if (!comm)
		return (ft_lstclear(&comm_lst, free), NULL);
	comm_lst = ops_a_append_nodes(comm_lst, cost_a, comm);
	if (!comm_lst)
		return (free(comm), NULL);
	return (free(comm), comm_lst);
}

static t_list	*ops_a_append_nodes(t_list *comm_lst, int cost_a, char *comm)
{
	char	*comm_cpy;
	t_list	*new;

	while (cost_a > 0)
	{
		comm_cpy = ft_strdup(comm);
		if (!comm_cpy)
			return (ft_lstclear(&comm_lst, free), NULL);
		new = ft_lstnew(comm_cpy);
		if (!new)
			return (ft_lstclear(&comm_lst, free), free(comm_cpy), NULL);
		ft_lstadd_back(&comm_lst, new);
		cost_a--;
	}
	return (comm_lst);
}
