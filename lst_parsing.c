/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 02:03:06 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/14 02:57:17 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(int nbr, t_stack *stack)
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

//Fetches in the dst_stack the dst index where the given nbr belongs
//Index solution issues: dst should be computed differently whether nbr should be set on the top or bottom part of dst_stack
int	get_dest(int nbr, t_stack *stack)
{
	int		dest;
	long	spread;
	t_stack	*stk_head;

	dest = 0;
	spread = 0;
	stk_head = stack;
	// if (stack->nbr > lst_max(stack))
	// 	return (get_pos(lst_max(stack), stack));
	// else if (nbr < lst_min(stack))
	// 	return (get_pos(lst_min(stack), stack) + 1);
	while (stack)
	{
		if (nbr > stack->nbr)
		{
			if (nbr - stack->nbr < spread || spread == 0)
			{
				spread = nbr - stack->nbr;
				dest = stack->nbr;
			}
		}
		stack = stack->next;
	}
	if (spread == 0)
		return (get_pos(lst_min(stk_head), stk_head) + 1);
	return (get_pos(dest, stk_head));
}

int	lst_orderchk(t_stack *stack)
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

int	lst_min(t_stack *lst)
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

int	lst_max(t_stack *lst)
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