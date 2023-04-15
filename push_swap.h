/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:23 by ohanchak          #+#    #+#             */
/*   Updated: 2023/04/15 16:00:28 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int	index;
	int	position_curent;
	int	position_target;
	int	data;
	int	arr_a;
	int	arr_b;
	struct s_node	*next;
}t_node;


void	sa(t_node **node);
#endif
