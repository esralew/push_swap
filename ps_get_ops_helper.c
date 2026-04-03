/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_ops_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:33:34 by elewin            #+#    #+#             */
/*   Updated: 2026/04/01 18:40:20 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to add a dummy node, that will be added by get_ops_a and get_ops_b,
// in case that no regular node had to be added (NULL return not possible,
// because possibility to distinguish allocation fails is necessary)
t_list	*insert_dummy(void)
{
	t_list	*dummy;
	char	*dummy_str;

	dummy_str = ft_strdup("dummy");
	if (!dummy_str)
		return (NULL);
	dummy = ft_lstnew(dummy_str);
	if (!dummy)
		return (free(dummy_str), NULL);
	return (dummy);
}

void	ft_lstdel_front(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(tmp, del);
}

void	ft_lstdel_back(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = ft_lst_scndlast(*lst);
	ft_lstdelone(tmp->next, del);
	tmp->next = NULL;
}

t_list	*find_max(t_list *stack)
{
	t_list	*curr;
	t_list	*max;
	int		max_val;

	curr = stack;
	max_val = *(int *)curr->content;
	max = curr;
	if (ft_lstsize(stack) < 2)
		return (max);
	curr = curr->next;
	while (1)
	{
		if (*(int *)curr->content > max_val)
		{
			max_val = *(int *)curr->content;
			max = curr;
		}
		if (!(curr->next))
			break ;
		curr = curr->next;
	}
	return (max);
}
