/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:28:20 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 19:14:45 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*cache;

	if (all->head_a && all->head_a->next)
	{
		p1 = all->head_a;
		p2 = all->head_a->next;
		cache = all->head_a->next->next;
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = cache;
		all->head_a = p2;
		all->head_a->next = p1;
	}
	if (all->size_a == 2)
		all->tail_a = p1;
	if (all->checker_on == 0)
		write(1, "sa\n", 3);
}

void	sb(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*cache;

	if (all->head_b && all->head_b->next)
	{
		p2 = all->head_b->next;
		p1 = all->head_b;
		cache = p2->next;
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = cache;
		all->head_b = p2;
		all->head_b->next = p1;
	}
	if (all->size_b == 2)
		all->tail_b = p1;
	if (all->checker_on == 0)
		write(1, "sb\n", 3);
}

int	sa_ss(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*cache;

	if (all->head_a && all->head_a->next)
	{
		p1 = all->head_a;
		p2 = all->head_a->next;
		cache = all->head_a->next->next;
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = cache;
		all->head_a = p2;
		all->head_a->next = p1;
		if (all->size_a == 2)
			all->tail_a = p1;
		return (1);
	}
	return (0);
}

int	sb_ss(t_ps *all)
{
	t_stack *p1;
	t_stack *p2;
	t_stack	*cache;

	if (all->head_b && all->head_b->next)
	{
		p2 = all->head_b->next;
		p1 = all->head_b;
		cache = p2->next;
		p2->prev = NULL;
		p2->next = p1;
		p1->prev = p2;
		p1->next = cache;
		all->head_b = p2;
		all->head_b->next = p1;
		if (all->size_b == 2)
			all->tail_b = p1;
		return (1);
	}
	return (0);
}
