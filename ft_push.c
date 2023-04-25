/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:13:34 by ohanchak          #+#    #+#             */
/*   Updated: 2023/04/15 16:13:58 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_node **node_a, t_node **node_b)
{
	t_node *tmp;
	if(node_a == NULL)
		return;
	tmp = (*node_a)->next;
	(*node_a)->next = *node_b;
	*node_b = *node_a;
	*node_a = tmp;
}

void	pa(t_node **node_a, t_node **node_b)
{
	push(node_b, node_a);
	ft_putstr("pa\n");

}

void	pb(t_node **node_a, t_node **node_b)
{
	push(node_a, node_b);
	ft_putstr("pb\n");
}