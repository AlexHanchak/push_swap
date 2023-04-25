/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:23 by ohanchak          #+#    #+#             */
/*   Updated: 2023/04/20 16:55:25 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				index;
	int				position_curent;
	int				position_target;
	int				data;
	int				arr_a;
	int				arr_b;
	int				value;
	struct s_node	*next;
}t_node;

void	sa(t_node **node);
void	sb(t_node **node);

void	pa(t_node *node);
void	pb(t_node *node);

void	ra(t_node *node);
void	rb(t_node *node);
void	rr(t_node *node);

void	rra(t_node **node);
void	rrb(t_node **node);
void	rrr(t_node **node);

// libft func

size_t	ft_strlen(const char *str);
void	ft_putstr(char const *s);

#endif