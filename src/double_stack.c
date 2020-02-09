/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:39:19 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 19:15:32 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ps *all)
{
	if (all->head_a && all->head_a->next && all->head_b && all->head_b->next)
	{
		if (sa_ss(all) && sb_ss(all))
			if (all->checker_on == 0)
				write(1, "ss\n", 3);
	}
}

void	rr(t_ps *all)
{
	ra(all);
	rb(all);
}


void	rrr(t_ps *all)
{
	rra(all);
	rrb(all);
}
