/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:03:31 by ohanchak          #+#    #+#             */
/*   Updated: 2023/04/20 16:56:21 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node *node)
{
	int	tmp;

	if(node == NULL || node->next->index == NULL)
		return;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	tmp = node->value;
	node->index = node->next->index;
	node->next->index = tmp;
}

void	sa(t_node **node_a)
{
	swap(*node_a);
    ft_putstr("sa\n");
}

void	sb(t_node **node_b)
{
	swap(*node_b);
	ft_putstr("sa\n");
}

void	ss(t_node **node_a, t_node **node_b)
{
	swap(*node_a);
	swap(*node_b);
	ft_putstr("sa\n");
}
