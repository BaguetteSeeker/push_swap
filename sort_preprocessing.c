/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_preprocessing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:24:03 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/21 19:44:53 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Strong stack opt. : remains to be implemented in order to solve 
//the growing deoptimization occuring with divergeant rot directions 
//as stack sizes vary more & more in siz from one another
size_t	move_cost(t_sort nbr)
{
	if (nbr.src_move == both || nbr.dst_move == both
		|| nbr.src_move == nbr.dst_move)
		return (ft_maxint(nbr.src_cost, nbr.dst_cost) + PUSH_COST);
	else
		return (nbr.src_cost + nbr.dst_cost + PUSH_COST);
}

//Evals necessarry rotations & their direction to properly prep the given stack
void	eval_rots(size_t pos, size_t lstsiz, size_t *move, size_t *cost)
{
	size_t	mid_threshold;

	if (pos == 0)
	{
		*move = both;
		*cost = 0;
		return ;
	}
	mid_threshold = lstsiz / 2;
	if (pos == mid_threshold)
	{
		if (lstsiz % 2)
		{
			*move = up;
			*cost = mid_threshold;
		}
		else
		{
			*move = both;
			*cost = lstsiz - pos;
		}
	}
	else if (pos > mid_threshold)
	{
		*move = down;
		*cost = lstsiz - pos;
	}
	else
	{
		*move = up;
		*cost = pos;
	}
}

t_sort	fetch_cheapest(t_stack *src, t_stack *dst,
	size_t src_siz, size_t dst_siz)
{
	t_sort	number;
	t_sort	cheapest;
	t_stack	*src_head;

	src_head = src;
	cheapest = (t_sort){0};
	cheapest.pos = -1;
	while (src)
	{
		number.pos = get_pos(src->nbr, src_head);
		eval_rots(number.pos, src_siz, &(number.src_move), &(number.src_cost));
		eval_rots(get_dest(src->nbr, dst), dst_siz,
			&(number.dst_move), &(number.dst_cost));
		number.full_cost = move_cost(number);
		if (number.full_cost < cheapest.full_cost || cheapest.pos == -1)
			cheapest = number;
		src = src->next;
	}
	return (cheapest);
}
