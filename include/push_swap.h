/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:50:08 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 20:46:38 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define WIDTH 1920
# define HEIGHT 1080

# include "ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>

typedef struct			s_stack
{
	int					num;
	struct s_stack		*next;
	struct s_stack		*prev;
	int					num_index;
}						t_stack;

typedef struct			s_ps
{
	t_stack				*a;
	t_stack				*b;
	int					total;
	int					size_a;
	int					size_b;
	t_stack				*head_a;
	t_stack				*tail_a;
	t_stack				*head_b;
	t_stack				*tail_b;
	int					max;
	int					min;
	int					checker_on;
	int					mark_type;
	int					flag;
}						t_ps;

void					error_exit(void);
int						*validator(int ac, char **av);
int						counter(char **av);
int						*convert(int count, char **av);
t_ps					*foo_stacks(int count, int *stack);
struct s_stack			*init(int data);
struct s_stack			*addelem(struct s_stack *stack, int data);
void					print_stack_tail(t_ps *all);
void					print_stack_head(t_ps *all);
struct s_stack			*init_empty(void);
struct s_stack			*add_empty(struct s_stack *stack);
void					print_ps(t_ps *all);
void					fill_linked_list(t_ps *all, int *stack);
void					set_index(struct s_stack *stack, int count, t_ps *all);
void					algo(t_ps *all, int br_n1);/*, int br_n2, int br_n3);*/
struct s_stack			*get_next_index(struct s_stack *stack, \
										int count, t_ps *all);
void					sa(t_ps *all);
int						sb_ss(t_ps *all);
int						sa_ss(t_ps *all);
void					ra(t_ps *all);
void					rra(t_ps *all);
void					sb(t_ps *all);
void					rb(t_ps *all);
void					rrb(t_ps *all);
void					ss(t_ps *all);
void					rr(t_ps *all);
void					rrr(t_ps *all);
void					pb(t_ps *all);
void					pa(t_ps *all);
void					ps_last_push_clear(t_ps *all, t_stack *a, t_stack *b);
void					do_best_for_three(t_ps *all);
void					solve_3_num(t_ps *all);
void					minisort_b(t_ps *all);
void					algo2(t_ps *all, int break_1, int break_2);
int						check_is_sorted(t_stack *stack);
void					do_best_of_three(t_ps *all);
void					do_for_middle(t_ps *all);
void					go_algo(t_ps *all);
void					reader(t_ps *all);
int						go_find_shortcut(t_ps *all, int min_index, \
														int max_index);
void					algo1(t_ps *all);
void					worse_but_works(t_ps *all);
void					final_rotate(t_ps *all);
int						check_command(t_ps *all, char *line);
void					output_args(int ac, char **av);
void					output_commands(int ac, char **av);

#endif
