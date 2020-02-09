/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:25:01 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 18:39:30 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;

	if (all->head_a && all->head_a->next)
	{
		p1 = all->head_a;
		p2 = all->head_a->next;
		p2->prev = NULL;
		p3 = all->tail_a;
		p3->next = p1;
		all->head_a = p2;
		all->head_a->next = p2->next;
		p3->prev = all->tail_a->prev;
		p1->prev = p3;
		p1->next = NULL;
		all->tail_a = p1;
		if (all->checker_on == 0)
			write(1, "ra\n", 3);
	}
}

void	rb(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;

	if (all->head_b && all->head_b->next)
	{
		p1 = all->head_b;
		p2 = all->head_b->next;
		p2->prev = NULL;
		p3 = all->tail_b;
		p3->next = p1;
		all->head_b = p2;
		all->head_b->next = p2->next;
		p3->prev = all->tail_b->prev;
		p1->prev = p3;
		p1->next = NULL;
		all->tail_b = p1;
		if (all->checker_on == 0)
			write(1, "rb\n", 3);
	}
}

void	rra(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;

	if ((all->head_a && all->tail_a) && all->size_a > 1)
	{
		p1 = all->tail_a;
		p2 = all->tail_a->prev;
		p1->prev = NULL;
		all->head_a->prev = p1;
		p1->next = all->head_a;
		p2->next = NULL;
		all->tail_a = p2;
		all->head_a = p1;
	}
	if (all->checker_on == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;

	if ((all->head_b && all->tail_b) && all->size_b > 1)
	{
		p1 = all->tail_b;
		p2 = all->tail_b->prev;
		p1->prev = NULL;
		all->head_b->prev = p1;
		p1->next = all->head_b;
		p2->next = NULL;
		all->tail_b = p2;
		all->head_b = p1;
	}
	if (all->checker_on == 0)
		write(1, "rrb\n", 4);
}
