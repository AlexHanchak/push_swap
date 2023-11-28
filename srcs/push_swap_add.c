/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:44:30 by ohanchak          #+#    #+#             */
/*   Updated: 2023/11/28 16:27:53 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_instructions(t_instruction *instr)
{
	size_t	nb;

	nb = 0;
	while (instr)
	{
		nb++;
		instr = instr->next;
	}
	return (nb);
}

t_state	*find_best_solution(t_state *states)
{
	t_state	*solution;
	t_state	*tmp_state;

	tmp_state = states->next;
	solution = NULL;
	while (tmp_state)
	{
		if (!solution || count_instructions(tmp_state->instructions)
			< count_instructions(solution->instructions))
		{
			solution = tmp_state;
		}
		tmp_state = tmp_state->next;
	}
	if (!solution)
		solution = states;
	return (solution);
}

void	execute_instructions_and_copy(t_program *prg, t_state *solution)
{
	if (solution->instructions)
	{
		execute_instructions(solution->instructions,
			&prg->stack_a, &prg->stack_b, prg->debug);
		prg->instr = copy_instructions(solution->instructions);
	}
}

int	pick_solution(t_program *prg, t_state *states)
{
	t_state	*solution;

	solution = find_best_solution(states);
	execute_instructions_and_copy(prg, solution);
	if (!prg->instr)
	{
		free_states(states);
		return (1);
	}
	return (0);
}
