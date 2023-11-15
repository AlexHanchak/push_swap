/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lex <lex@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:33:24 by lex               #+#    #+#             */
/*   Updated: 2023/10/05 16:37:11 by lex              ###   ########.fr       */
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
