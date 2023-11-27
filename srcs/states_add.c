/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:31:50 by ohanchak          #+#    #+#             */
/*   Updated: 2023/11/27 17:35:41 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state	*create_state_with_stack(t_stack *stack, size_t max_size)
{
	t_state	*state;

	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	state->instructions = NULL;
	state->last_instr = NULL;
	state->next = NULL;
	if (stack)
		state->stack_a = copy_stack(stack);
	else
	{
		state->stack_a = new_empty_stack(max_size);
		if (!state->stack_a)
		{
			free(state);
			return (NULL);
		}
	}
	return (state);
}

t_state	*new_empty_state(t_stack *stack_a, t_stack *stack_b, size_t max_size)
{
	t_state	*state;

	state = create_state_with_stack(stack_a, max_size);
	if (!state)
		return (NULL);
	if (stack_b)
		state->stack_b = copy_stack(stack_b);
	else
	{
		state->stack_b = new_empty_stack(max_size);
		if (!state->stack_b)
		{
			free_stack(state->stack_a);
			free(state);
			return (NULL);
		}
	}
	return (state);
}
