/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:11:20 by sscottie          #+#    #+#             */
/*   Updated: 2020/01/09 16:39:43 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol_ps(const char *str)
{
	int		negative;
	long	res;

	res = 0;
	negative = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' \
			|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' && str++)
		negative = -1;
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + ((int)*str - 48);
		str++;
	}
	return (res * negative);
}

static int	validate(int *stack, int temp)
{
	int i;

	i = 0;
	while (stack[i] != '\0')
	{
		if (stack[i] == temp)
			return (0);
		i++;
	}
	return (1);
}

static void	cutter(int count, int *stack, char **av)
{
	int		i;
	char	**temp;
	int		j;
	int		k;

	i = 0;
	k = 1;
	while (i != count)
	{
		j = 0;
		temp = ft_strsplit(av[k], ' ');
		while (temp[j] != NULL)
		{
			if (ft_atol_ps(temp[j]) >= INT_MIN && ft_atol_ps(temp[j]) \
				<= INT_MAX && (validate(stack, ft_atoi(temp[j])) == 1))
				stack[i++] = ft_atoi(temp[j++]);
			else
				error_exit();
		}
		while (--j != -1)
			free(temp[j]);
		free(temp);
		temp = NULL;
		k++;
	}
}

int			*convert(int count, char **av)
{
	int		*stack;

	stack = (int*)malloc(sizeof(int) * count);
	ft_bzero(stack, count);
	cutter(count, stack, av);
	return (stack);
}
