/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:16:43 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 18:39:27 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_data(t_stack *from, t_stack *to)
{
	to->num = from->num;
	to->num_index = from->num_index;
}

void	ps_clear_push(t_ps *all, t_stack *a, t_stack *b)
{
	t_stack	*p1;
	t_stack	*p2;

	if (a)
	{
		p1 = all->head_a;
		p2 = all->head_a->next;
		p2->prev = NULL;
		p2->next = all->head_a->next->next;
		all->head_a = p2;
		free(p1);
	}
	if (b)
	{
		p1 = all->head_b;
		p2 = all->head_b->next;
		p2->prev = NULL;
		p2->next = all->head_b->next->next;
		all->head_b = p2;
		free(p1);
	}
}

void	pb(t_ps *all)
{
	t_stack *cache;

	if (all->head_b == NULL && all->head_a != NULL)
	{	
		all->head_b = init_empty();
		copy_data(all->head_a, all->head_b);
		all->head_b->next = NULL;
		ps_clear_push(all, all->a, NULL);
		all->b = all->head_b;
		all->tail_b = all->head_b;
		all->size_b++;
		all->size_a--;
	}
	else if (all->head_b != NULL && all->head_a != NULL && all->head_a->next == NULL)
	{
		cache = init_empty();
		copy_data(all->head_a, cache);
		cache->next = all->head_b;
		all->head_b->prev = cache;
		cache->prev = NULL;
		free(all->head_a);
		all->head_a = NULL;
		all->head_b = cache;
		all->b = all->head_b;
		all->size_b++;
		all->size_a--;
	}
	else if (all->head_b != NULL && all->head_a != NULL)
	{
		cache = init_empty();
		copy_data(all->head_a, cache);
		cache->next = all->head_b;
		all->head_b->prev = cache;
		cache->prev = NULL;
		ps_clear_push(all, all->a, NULL);
		all->head_b = cache;
		all->b = all->head_b;
		all->size_b++;
		all->size_a--;
		if (all->head_a->next == NULL)
			all->tail_a = all->head_a;
	}
	if (all->checker_on == 0)
		write(1, "pb\n", 3);
}

void	pa(t_ps *all)
{
	t_stack *cache;

	if (all->head_a == NULL && all->head_b != NULL)
	{	
		all->head_a = init_empty();
		copy_data(all->head_b, all->head_a);
		all->head_a->next = NULL;
		ps_clear_push(all, NULL, all->b);
		all->a = all->head_a;
		all->tail_a = all->head_a;
		all->size_a++;
		all->size_b--;
	}
	else if (all->head_a != NULL && all->head_b != NULL && all->head_b->next == NULL)
	{
		cache = init_empty();
		copy_data(all->head_b, cache);
		cache->next = all->head_a;
		all->head_a->prev = cache;
		cache->prev = NULL;
		free(all->head_b);
		all->head_b = NULL;
		all->head_a = cache;
		all->a = all->head_a;
		all->size_a++;
		all->size_b--;
	}
	else if (all->head_a != NULL && all->head_b != NULL)
	{
		cache = init_empty();
		copy_data(all->head_b, cache);
		cache->next = all->head_a;
		all->head_a->prev = cache;
		cache->prev = NULL;
		ps_clear_push(all, NULL, all->head_b);
		all->head_a = cache;
		all->a = all->head_a;
		all->size_a++;
		all->size_b--;
		if (all->head_b->next == NULL)
			all->tail_b = all->head_b;
	}
	if (all->checker_on == 0)
		write(1, "pa\n", 3);
}
