/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 09:27:39 by lex               #+#    #+#             */
/*   Updated: 2023/10/05 16:35:10 by lex              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int				is_stack_ordered(t_stack *stack, int order)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if ((order == ASC && stack->array[i] >= stack->array[i + 1])
			|| (order == DESC && stack->array[i] <= stack->array[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int				stack_contains(t_stack *stack, int num)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i++] == num)
			return (1);
	}
	return (0);
}

t_stack			*copy_stack(t_stack *stack)
{
	size_t		i;
	t_stack		*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(new->array = malloc(sizeof(int) * stack->max_size)))
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		new->array[i] = stack->array[i];
		i++;
	}
	new->size = stack->size;
	new->max_size = stack->max_size;
	return (new);
}

t_stack			*new_empty_stack(size_t max_size)
{
	t_stack		*stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
	if (!(stack->array = malloc(sizeof(int) * max_size)))
	{
		free(stack);
		return (NULL);
	}
	stack->max_size = max_size;
	stack->size = 0;
	return (stack);
}
