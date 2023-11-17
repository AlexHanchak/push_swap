/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:22:17 by ohanchak          #+#    #+#             */
/*   Updated: 2023/04/15 16:03:40 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 

#include "push_swap.h"

void			free_instructions(t_instruction *instructions)
{
	t_instruction	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->line);
		free(instructions);
		instructions = next;
	}
}

void			free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void			free_prg(t_program *prg)
{
	free_instructions(prg->instr);
	free(prg->stack_a.array);
	free(prg->stack_b.array);
}
