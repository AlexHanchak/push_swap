/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:21:34 by ohanchak          #+#    #+#             */
/*   Updated: 2023/11/28 16:40:39 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_align_a(size_t *pos, size_t *mvt, t_stack *stack_a,
t_stack *stack_b)
{
	*pos = 0;
	*mvt = 0;
	if (is_stack_ordered(stack_a, ASC))
	{
		while (*pos < stack_a->size - 1
			&& stack_a->array[*pos] < stack_a->array[*pos + 1])
			(*pos)++;
		if (*pos > stack_b->size / 2)
			*mvt = stack_a->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

void	calcul_align_b(size_t *pos, size_t *mvt, t_stack *stack_b)
{
	*pos = 0;
	*mvt = 0;
	if (is_stack_ordered(stack_b, DESC))
	{
		while (*pos < stack_b->size - 1
			&& stack_b->array[*pos] > stack_b->array[*pos + 1])
			(*pos)++;
		if (*pos > stack_b->size / 2)
			*mvt = stack_b->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

int	align_stack_a(t_program *prg)
{
	size_t			i;
	size_t			num;
	t_instruction	*tmp;

	calcul_align_a(&i, &num, &prg->stack_a, &prg->stack_b);
	while (num--)
	{
		if (i > prg->stack_b.size / 2)
			tmp = add_instruction(&prg->instr, "rra");
		else
			tmp = add_instruction(&prg->instr, "ra");
		if (!tmp)
			return (1);
		execute_instructions(tmp, &prg->stack_a, &prg->stack_b, prg->debug);
	}
	return (0);
}

int	align_stack_b(t_program *prg)
{
	size_t			i;
	size_t			num;
	t_instruction	*tmp;

	calcul_align_b(&i, &num, &prg->stack_b);
	while (num--)
	{
		if (i > prg->stack_b.size / 2)
			tmp = add_instruction(&prg->instr, "rrb");
		else
			tmp = add_instruction(&prg->instr, "rb");
		if (!tmp)
			return (1);
		execute_instructions(tmp, &prg->stack_a, &prg->stack_b, prg->debug);
	}
	return (0);
}
