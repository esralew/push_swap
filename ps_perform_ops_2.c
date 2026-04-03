/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_perform_ops_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:22:54 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 16:55:10 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rra(t_list *node)
{
	char	*cont;

	cont = (char *)node->content;
	if (ft_strncmp(cont, "rra", 3) == 0)
		return (1);
	else
		return (0);
}

int	check_rb(t_list *node)
{
	char	*cont;

	cont = (char *)node->content;
	if (ft_strncmp(cont, "rb", 3) == 0)
		return (1);
	else
		return (0);
}

int	check_rrb(t_list *node)
{
	char	*cont;

	cont = (char *)node->content;
	if (ft_strncmp(cont, "rrb", 3) == 0)
		return (1);
	else
		return (0);
}

int	check_rr(t_list *node)
{
	char	*cont;

	cont = (char *)node->content;
	if (ft_strncmp(cont, "rr", 3) == 0)
		return (1);
	else
		return (0);
}

int	check_rrr(t_list *node)
{
	char	*cont;

	cont = (char *)node->content;
	if (ft_strncmp(cont, "rrr", 3) == 0)
		return (1);
	else
		return (0);
}
