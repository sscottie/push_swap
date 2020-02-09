/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   production.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:02:45 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 20:48:03 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*foo_stacks(int count, int *stack)
{
	t_ps	*all;
	int		i;

	i = 0;
	if (!(all = (t_ps *)malloc(sizeof(t_ps))))
		exit(EXIT_FAILURE);
	all->head_b = NULL;
	all->total = count;
	fill_linked_list(all, stack);
	set_index(all->a, count, all);
	all->min = 0;
	return (all);
}

void	fill_linked_list(t_ps *all, int *stack)
{
	int	i;

	i = 0;
	while (i < all->total)
	{
		if (i == 0)
		{
			all->a = init(stack[i]);
			all->head_a = all->a;
			all->size_a = 1;
		}
		else
		{
			all->a = addelem(all->a, stack[i]);
			all->tail_a = all->a;
			all->size_a++;
		}
		i++;
	}
}

void	go_algo(t_ps *all)
{
	if (!check_is_sorted(all->head_a))
	{
		if (all->size_a == 2)
			sa(all);
		else if (all->size_a == 3)
			do_best_of_three(all);
		else if (all->size_a > 3 && all->size_a < 10)
			do_for_middle(all);
		else if (all->size_a >= 10 && all->size_a <= 100)
			worse_but_works(all);
		else
			algo(all, all->total * 9 / 10);
	}
}

int		check_is_sorted(t_stack *stack)
{
	int		i;

	i = stack->num_index;
	while (stack != NULL)
	{
		if (stack->num_index == i)
		{
			i++;
			stack = stack->next;
		}
		else
			return (0);
	}
	return (1);
}

void	set_index(struct s_stack *stack, int count, t_ps *all)
{
	t_stack		*ret;
	int			index;

	index = 0;
	while ((ret = get_next_index(stack, count, all)))
		ret->num_index = index++;
	all->max = index - 1;
}
