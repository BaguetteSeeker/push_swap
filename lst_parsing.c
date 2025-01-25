/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 02:03:06 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/25 23:06:44 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(int nbr, t_nbrlst *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->nbr == nbr)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

//Fetches in the dst stack the dst index where the given nbr belongs
int	get_dest(int nbr, t_nbrlst *stack, size_t stance)
{
	int			target_nbr;
	long		spread;
	t_nbrlst	*stk_head;

	target_nbr = 0;
	spread = 0;
	stk_head = stack;
	while (stack)
	{
		if ((stance == REVERSE && nbr > stack->nbr)
			|| (stance == OBVERSE && nbr < stack->nbr))
		{
			if (nbr - stack->nbr < spread || spread == 0)
			{
				spread = nbr - stack->nbr;
				target_nbr = stack->nbr;
			}
		}
		stack = stack->next;
	}
	if (spread == 0 && stance == REVERSE)
		return (get_pos(lst_min(stk_head), stk_head) + 1);
	else if (spread == 0 && stance == OBVERSE)
		return (get_pos(lst_max(stk_head), stk_head) + 1);
	return (get_pos(target_nbr, stk_head));
}

int	lst_orderchk(t_nbrlst *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (i > stack->nbr)
			return (0);
		i = stack->nbr;
		stack = stack->next;
	}
	return (1);
}

int	lst_min(t_nbrlst *lst)
{
	int	min;

	min = lst->nbr;
	while (lst)
	{
		if (min > lst->nbr)
			min = lst->nbr;
		lst = lst->next;
	}
	return (min);
}

int	lst_max(t_nbrlst *lst)
{
	int	max;

	max = lst->nbr;
	while (lst)
	{
		if (max < lst->nbr)
			max = lst->nbr;
		lst = lst->next;
	}
	return (max);
}
