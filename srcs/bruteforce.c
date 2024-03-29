/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:10:46 by ohanchak          #+#    #+#             */
/*   Updated: 2023/11/17 18:16:07 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bruteforce_solution(t_state *states, t_state **result)
{
	while (states && !(*result))
	{
		if (!states->stack_b->size && !is_stack_ordered(states->stack_a, ASC))
		{
			if (!add_state(result, states))
			{
				free_states(states);
				return (1);
			}
		}
		states = states->next;
	}
	return (0);
}

t_state	*pick_bruteforce_solution(t_state *states, size_t pos[2],
t_stack *stack_b)
{
	t_state			*result;
	t_state			*new_states;
	t_state			*tmp;

	result = NULL;
	while (!result)
	{
		new_states = NULL;
		tmp = states;
		while (tmp)
		{
			if (bruteforce_choice_a(&new_states, tmp, pos, stack_b))
			{
				free_states(new_states);
				return (NULL);
			}
			tmp = tmp->next;
		}
		free_states(states);
		states = new_states;
		if (check_bruteforce_solution(states, &result))
			return (NULL);
	}
	free_states(states);
	return (result);
}

int	bruteforce_order_a(t_program *prg)
{
	size_t			pos[2];
	t_state			*result;
	t_state			*states;

	calcul_align_b(&pos[0], &pos[1], &prg->stack_b);
	states = new_empty_state(&prg->stack_a, NULL, prg->stack_a.max_size);
	if (!states)
		return (1);
	result = pick_bruteforce_solution(states, pos, &prg->stack_b);
	if (!result)
	{
		free_states(states);
		return (1);
	}
	execute_instructions(result->instructions, &prg->stack_a, &prg->stack_b,
		prg->debug);
	if (!copy_and_concat_instructions(&prg->instr, result->instructions))
	{
		free_states(result);
		return (1);
	}
	free_states(result);
	return (0);
}
