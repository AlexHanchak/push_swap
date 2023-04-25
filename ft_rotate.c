/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:07:58 by ohanchak          #+#    #+#             */
/*   Updated: 2023/04/15 16:09:04 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **node)
{
	t_node *tmp;
	t_node *end;

	tmp = *node;
	*node = (*node)->next;
//	end = ??
	tmp->next = NULL;
	end->next = tmp;
}

void	ra(t_node **node_a)
{
	rotate(node_a);
	ft_putstr("ra\n");
}

void	rb(t_node **node_b)
{
	rotate(node_b);
	ft_putstr("ra\n");
}

void	rr(t_node **node_a, t_node **node_b)
{
	rotate(node_a);
	rotate(node_b);
	ft_putstr("rr\n");
}