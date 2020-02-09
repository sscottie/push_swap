/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 02:48:44 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/06 02:48:46 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int		*init_stack;
	int		count;
	t_ps	*all;

	init_stack = validator(ac, av);
	if (init_stack == NULL)
		error_exit();
	count = counter(av);
	all = foo_stacks(count, init_stack);
	all->checker_on = 0;
	go_algo(all);
	free(init_stack);
	return (0);
}
