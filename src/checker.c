/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:01:31 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/08 14:01:32 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*init_stack;
	int		count;
	t_ps	*all;

	init_stack = validator(ac, av);
	if (init_stack == NULL)
		error_exit();
	count = counter(av);
	if (count == 1)
		return (0);
	all = foo_stacks(count, init_stack);
	all->checker_on = 1;
	reader(all);
	free(init_stack);
	return (0);
}
