/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:34:43 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 19:03:28 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dooble(int count, int *av)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (av[i] == av[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_only_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' || av[i][j] == '\n' || av[i][j] == '\t' \
				|| av[i][j] == '\f' || av[i][j] == '\v' || av[i][j] == '\r')
				j++;
			if (((av[i][j] == '-' || av[i][j] == ' ') \
				&& (av[i][j + 1] != '-' || av[i][j + 1] != ' ')) \
				|| ((av[i][j] == '+' || av[i][j] == ' ') \
				&& (av[i][j + 1] != '+' || av[i][j + 1] != ' ')))
				j++;
			if (!ft_isdigit(av[i][j]) && av[i][j] != '\0')
				return (0);
			while (ft_isdigit(av[i][j]))
				j++;
		}
		i++;
	}
	return (1);
}

int		*validator(int ac, char **av)
{
	int	i;
	int	count;
	int	*init_stack;

	i = 0;
	if (ac >= 2 && check_only_number(ac, av) == 1)
	{
		count = counter(av);
		init_stack = convert(count, av);
	}
	else
		return (NULL);
	if (check_dooble(count, init_stack) != 1)
	{
		free(init_stack);
		return (NULL);
	}
	return (init_stack);
}
