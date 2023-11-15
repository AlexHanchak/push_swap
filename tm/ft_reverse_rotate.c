/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:07:58 by ohanchak          #+#    #+#             */
/*   Updated: 2023/04/15 16:09:38 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_node **node)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*before_tail;

	tail = get_stack_bottom(*node);
	before_tail = get_stack_before_bottom(*node);
	tmp = *node;
	*node = tail;
	(*node)->next = tmp;
	before_tail->next = NULL;
}

void	rra(t_node **node_a)
{
	reverse_rotate(node_a);
	ft_putstr("rra\n");
}

void	rrb(t_node **node_b)
{
	reverse_rotate(node_b);
	ft_putstr("rrb\n");
}

void	rrr(t_node **node_a, t_node **node_b)
{
	reverse_rotate(node_a);
	reverse_rotate(node_b);
	ft_putstr("rrr\n");
}