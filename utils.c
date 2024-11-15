/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:24:43 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/14 22:54:50 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(long *val1, long *val2)
{
	long	tmpval;

	tmpval = *val1;
	*val1 = *val2;
	*val2 = tmpval;
}

int	min_array(int arr[], size_t siz)
{
	int		min;
	size_t	i;

	i = 1;
	min = arr[0];
	while (i < siz)
	{
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	return (min);
}

int	max_array(int arr[], size_t siz)
{
	int		max;
	size_t	i;

	i = 1;
	max = arr[0];
	while (i < siz)
	{
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}