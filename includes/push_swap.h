/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:20:10 by ohanchak          #+#    #+#             */
/*   Updated: 2023/12/02 17:54:31 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define DEPTH		5

# define ASC		0
# define DESC		1

typedef struct s_stack
{
	int				*array;
	size_t			size;
	size_t			max_size;
}					t_stack;

typedef struct s_instruction
{
	char			*line;
	void			*next;
	void			*prev;
}					t_instruction;

typedef struct s_state
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_instruction	*instructions;
	t_instruction	*last_instr;
	void			*next;
}					t_state;

typedef struct s_program
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_instruction	*instr;
	int				debug;
}					t_program;

void				reverse_rotate_stack(t_stack *stack);
void				rotate_stack(t_stack *stack);
void				push_stack(t_stack *stack1, t_stack *stack2);
void				swap_stack(t_stack *stack);

int					is_stack_ordered(t_stack *stack, int order);
int					stack_contains(t_stack *stack, int num);
t_stack				*copy_stack(t_stack *stack);
int					init_stacks(int argc, char *argv[],
						t_stack *stack_a, t_stack *stack_b);
t_stack				*new_empty_stack(size_t max_size);

void				calcul_align_a(size_t *pos, size_t *mvt, t_stack *stack_a,
						t_stack *stack_b);
void				calcul_align_b(size_t *pos, size_t *mvt, t_stack *stack_b);
int					align_stack_a(t_program *prg);
int					align_stack_b(t_program *prg);

void				execute_instructions(t_instruction *instr, t_stack *stack_a,
						t_stack *stack_b, int debug);
t_instruction		*copy_and_concat_instructions(t_instruction **instr,
						t_instruction *new);
t_instruction		*copy_instructions(t_instruction *instructions);
t_instruction		*add_n_instructions(t_instruction **instructions,
						char *line, size_t n);
t_instruction		*add_instruction(t_instruction **instructions, char *line);

int					can_pb(t_stack *stack_a, t_stack *stack_b);
size_t				closer_pos_to_inf(int nb, t_stack *stack);
size_t				less_mvt_at_begin(size_t minimal_mvt, size_t *min_mvt,
						t_stack *stack_a, t_stack *stack_b);
size_t				less_mvt_at_end(size_t minimal_mvt, size_t *min_mvt,
						t_stack *stack_a, t_stack *stack_b);

t_state				*new_state_instruction(t_state **states, t_state *old_state,
						char *line);
void				free_states(t_state *states);
t_state				*add_state(t_state **states, t_state *state_from);
t_state				*new_empty_state(t_stack *stack_a, t_stack *stack_b,
						size_t max_size);
t_state				*new_empty_state(t_stack *stack_a, t_stack *stack_b,
						size_t max_size);

int					pick_solution(t_program *prg, t_state *states);
int					create_states_resolution(t_state	**states);
t_instruction		*rotate_a(t_state *stt, size_t min[2], size_t min_mvt[2]);
t_instruction		*rotate(t_state *stt);
int					large_resolve(t_state *states);

int					check_bruteforce_solution(t_state *states,
						t_state **result);
t_state				*pick_bruteforce_solution(t_state	*states, size_t pos[2],
						t_stack *stack_b);
int					bruteforce_order_a(t_program *prg);

int					reverse_rotate_bruteforce_a(t_state **new_states,
						t_state *tmp, size_t pos[2], t_stack *stack_b);
int					rotate_bruteforce_a(t_state **new_states, t_state *tmp,
						size_t pos[2], t_stack *stack_b);
int					bruteforce_choice_a(t_state **new_states, t_state *tmp,
						size_t pos[2], t_stack *stack_b);

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *s);
void				ft_putnbr(int n);
int					ft_atoi(const char *str, int *num);

void				free_prg(t_program *prg);
void				free_instructions(t_instruction *instructions);
void				free_stack(t_stack *stack);

void				print_instruction(t_instruction *instr);
void				print_instructions(t_instruction *instr);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);

void				write_n_char(int n, char c);
int					size_nbr(int n);
int					get_max_size_nbr_stack(t_stack *stack);

#endif
