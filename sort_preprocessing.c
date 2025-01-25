/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_preprocessing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:24:03 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/25 22:56:45 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Strong stack opt. : remains to be implemented in order to solve 
//the growing deoptimization occuring with divergeant rot directions 
//as stack sizes vary more & more in siz from one another
static size_t	move_cost(t_sort src, t_sort dst)
{
	if (src.side == both || dst.side == both
		|| src.side == dst.side)
		return (ft_maxint(src.cost, dst.cost) + PUSH_COST);
	else
		return (src.cost + dst.cost + PUSH_COST);
}

//Evals and stores within the provided t_sort struct the minimum 
//rotation cost and optimized direction to position 
//the given number on top of the stack of size lstsize
void	eval_rots(size_t pos, size_t lstsiz, t_sort *sort)
{
	size_t	mid_threshold;

	if (pos == 0)
	{
		*sort = (t_sort){.side = both, .cost = 0};
		return ;
	}
	mid_threshold = lstsiz / 2;
	if (pos == mid_threshold)
	{
		if (lstsiz % 2)
			*sort = (t_sort){.side = up, .cost = mid_threshold};
		else
			*sort = (t_sort){.side = both, .cost = lstsiz - pos};
	}
	else if (pos > mid_threshold)
		*sort = (t_sort){.side = down, .cost = lstsiz - pos};
	else
		*sort = (t_sort){.side = up, .cost = pos};
}

void	fetch_cheapest(t_stack *src, t_stack *dst, t_stacks *stacks)
{
	t_sort		tmpsrc;
	t_sort		tmpdst;
	size_t		tmpcost;
	t_nbrlst	*tmp;

	tmpsrc = (t_sort){0};
	tmpdst = (t_sort){0};
	tmp = src->list;
	stacks->cheap_cost = NO_COST;
	while (tmp)
	{
		eval_rots(get_pos(tmp->nbr, src->list), src->size, &tmpsrc);
		eval_rots(get_dest(tmp->nbr, dst->list, REVERSE), dst->size, &tmpdst);
		tmpcost = move_cost(tmpsrc, tmpdst);
		if (tmpcost < stacks->cheap_cost || stacks->cheap_cost == NO_COST)
		{
			src->moves = tmpsrc;
			dst->moves = tmpdst;
			stacks->cheap_cost = tmpcost;
		}
		tmp = tmp->next;
	}
}
