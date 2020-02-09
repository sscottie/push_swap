/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:01:48 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/08 14:01:50 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*init_empty(void)
{
	struct s_stack *stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

struct s_stack	*init(int data)
{
	struct s_stack *stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->num = data;
	stack->prev = NULL;
	stack->next = NULL;
	stack->num_index = -1;
	return (stack);
}

struct s_stack	*add_empty(struct s_stack *stack)
{
	struct s_stack *temp;
	struct s_stack *pointer;

	temp = (struct s_stack *)malloc(sizeof(struct s_stack));
	pointer = stack->next;
	stack->next = temp;
	temp->next = pointer;
	temp->prev = stack;
	if (pointer != NULL)
		pointer->prev = temp;
	return (temp);
}

struct s_stack	*addelem(struct s_stack *stack, int data)
{
	struct s_stack *temp;
	struct s_stack *pointer;

	temp = (struct s_stack *)malloc(sizeof(struct s_stack));
	pointer = stack->next;
	stack->next = temp;
	temp->num = data;
	temp->next = pointer;
	temp->prev = stack;
	temp->num_index = -1;
	if (pointer != NULL)
		pointer->prev = temp;
	return (temp);
}

struct s_stack	*get_next_index(struct s_stack *stack, int count, t_ps *all)
{
	int				i;
	int				has_min;
	t_stack			*min;
	t_stack			*current;

	min = NULL;
	if (stack)
	{
		i = 0;
		has_min = 0;
		current = all->head_a;
		while (i < count)
		{
			if ((current->num_index == -1)
				&& (!has_min || current->num < min->num))
			{
				has_min = 1;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}
