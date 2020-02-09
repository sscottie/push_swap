/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:02:00 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/08 14:02:02 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_head(t_ps *all)
{
	t_stack	*p;

	p = all->head_a;
	while (p != NULL)
	{
		ft_printf("%d\n", p->num_index);
		p = p->next;
	}
}

void	print_stack_tail(t_ps *all)
{
	t_stack	*p;

	p = all->tail_a;
	while (p != NULL)
	{
		ft_printf("%d\n", p->num);
		p = p->prev;
	}
}

void	print_ps(t_ps *all)
{
	t_stack	*p1;
	t_stack	*p2;

	p1 = all->head_a;
	p2 = all->head_b;
	ft_printf("-----------------------------\n");
	ft_printf("|      A      |      B      |\n");
	ft_printf("-----------------------------\n");
	while (p1 != NULL || p2 != NULL)
	{
		if (p1)
		{
			ft_printf("| %-11d |", p1->num_index);
			p1 = p1->next;
		}
		else
			ft_printf("|             |");
		if (p2)
		{
			ft_printf(" %11d |\n", p2->num_index);
			p2 = p2->next;
		}
		else
			ft_printf("             |\n");
	}
}
