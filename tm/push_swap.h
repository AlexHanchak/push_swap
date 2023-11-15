/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:23 by ohanchak          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/20 16:55:25 by ohanchak         ###   ########.fr       */
=======
/*   Updated: 2023/04/29 17:44:07 by lex              ###   ########.fr       */
>>>>>>> 29e4b4ad78de5d89e0dfe886f94a583fc028017b
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

t_node	*get_stack_bottom(t_node *node);
t_node	*get_stack_before_bottom(t_node *node);
t_node	*stack_new(int value);

void	ss(t_node **node_a, t_node **node_b);
void	sa(t_node **node_a);
void	sb(t_node **node_b);

void	pa(t_node **node_a, t_node **node_b);
void	pb(t_node **node_a, t_node **node_b);

void	rotate(t_node **node);
void	ra(t_node **node_a);
void	rb(t_node **node_b);
void	rr(t_node **node_a, t_node **node_b);

void	rra(t_node **node_a);
void	rrb(t_node **node_b);
void	rrr(t_node **node_a, t_node **node_b);

// libft func

size_t	ft_strlen(const char *str);
void	ft_putstr(char const *s);

#endif