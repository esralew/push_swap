/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:23:37 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:18:58 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_lstsize(t_list *lst)
{
	int		nodes;
	t_list	*current;

	if (!lst)
		return (0);
	nodes = 1;
	current = lst;
	while (current->next)
	{
		nodes++;
		current = current->next;
	}
	return (nodes);
}
