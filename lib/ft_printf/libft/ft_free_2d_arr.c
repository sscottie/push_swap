/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 05:48:08 by sscottie          #+#    #+#             */
/*   Updated: 2020/02/09 18:14:33 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (--i != -1)
		free(str[i]);
	free(str);
}
