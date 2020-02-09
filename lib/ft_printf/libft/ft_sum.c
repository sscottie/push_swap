/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:55:56 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 18:07:22 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sum(int count, const int *arr)
{
	int	res;

	res = 0;
	while (count > 0)
	{
		res = res + arr[count];
		count--;
	}
	return (res);
}
