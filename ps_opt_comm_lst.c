/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opt_comm_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:22:31 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 17:22:57 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*merge_ops(t_list *p1, t_list *p2, t_list **comm_lst);
static t_list	*update_p1(t_list *p1);

// we leave the dummy node from get_ops_a() in comm_lst, so if there is only
// one node in comm_lst, that means there aren't any operations inside comm_lst
// and we return the comm_lst unchanged
// -> prevention of dereferencing NULL
t_list	*opt_comm_lst(t_list **comm_lst)
{
	t_list	*p1;
	t_list	*p2;
	size_t	p1_len;
	size_t	p2_next_len;
	t_list	*opt_comm_lst;

	if (ft_lstsize(*comm_lst) == 1)
		return (*comm_lst);
	p1 = (*comm_lst)->next;
	p2 = *comm_lst;
	if (check_b_op(p1) || check_a_op(ft_lstlast(*comm_lst)))
		return (*comm_lst);
	while (check_a_op(p2->next))
		p2 = p2->next;
	p1_len = ft_strlen((char *)p1->content);
	p2_next_len = ft_strlen((char *)p2->next->content);
	if (p1_len != p2_next_len)
		return (*comm_lst);
	opt_comm_lst = merge_ops(p1, p2, comm_lst);
	return (opt_comm_lst);
}

static t_list	*merge_ops(t_list *p1, t_list *p2, t_list **comm_lst)
{
	while (p2->next)
	{
		if (!update_p1(p1))
			return (NULL);
		ft_lstdel_back(comm_lst, free);
		if (p1 == p2)
			break ;
		p1 = p1->next;
	}
	return (*comm_lst);
}

static t_list	*update_p1(t_list *p1)
{
	char	*new_comm;

	if (check_ra(p1))
	{
		new_comm = ft_strdup("rr");
		if (!new_comm)
			return (NULL);
		free(p1->content);
		p1->content = new_comm;
	}
	if (check_rra(p1))
	{
		new_comm = ft_strdup("rrr");
		if (!new_comm)
			return (NULL);
		free(p1->content);
		p1->content = new_comm;
	}
	return (p1);
}

int	check_a_op(t_list *node)
{
	if (check_ra(node) || check_rra(node))
		return (1);
	else
		return (0);
}

int	check_b_op(t_list *node)
{
	if (check_rb(node) || check_rrb(node))
		return (1);
	else
		return (0);
}
