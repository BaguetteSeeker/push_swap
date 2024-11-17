/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 02:03:06 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/17 15:24:35 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(int nbr, t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		pos++;
		if (stack->nbr == nbr)
			return (pos);
		stack = stack->next;
	}
	return (-1);
}

// t_stack	*index_lstvals(t_stack *stack)
// {
// 	t_stack	*start;
// 	int		index;

// 	index = 0;
// 	start = stack;
// 	while (stack->next)
// 	{
// 		stack->index = index++;
// 		stack = stack->next;
// 	}
// 	return (stack);
// }

int	get_dest(int nbr, t_stack *stack)
{
	int	dest;

	dest = 1;
	if (stack->nbr > lst_max(stack))
		return (dest);
	//else if () if nbr < lstmin
		//return (); dest will be lstsiz
	while (stack)
	{
		if (nbr > stack->nbr)
			return (dest);
		dest++;
		stack = stack->next;
	}
	return (-1);
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