/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:30:15 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/25 23:05:14 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_stack(t_stack *stack, char ps)
{
	void	(*psptr)(t_nbrlst**, int);
	t_sort	moves;

	moves = (t_sort){0};
	if (ps == 'b')
	{
		eval_rots(get_pos(lst_max(stack->list),
				stack->list), stack->size, &moves);
		if (moves.side == up)
			psptr = &ps_rb;
		else
			psptr = &ps_rrb;
		while (moves.cost-- != 0)
			psptr(&(stack->list), 0);
	}
	else
	{
		eval_rots(get_pos(lst_min(stack->list),
				stack->list), stack->size, &stack->moves);
		if (moves.side == up)
			psptr = &ps_ra;
		else
			psptr = &ps_rra;
		while (moves.cost-- != 0)
			psptr(&(stack->list), 0);
	}
}

static void	duo_rot(t_sort moves, t_nbrlst **a, t_nbrlst **b)
{
	while (moves.cost-- != 0)
	{
		if (moves.side == up)
			ps_rr(a, b, 0);
		else
			ps_rrr(a, b, 0);
	}
}

static void	rot(t_nbrlst **target, t_sort moves, char ps)
{
	while (moves.cost-- != 0)
	{
		if (ps == 'a')
		{
			if (moves.side == up)
				ps_ra(target, 0);
			else
				ps_rra(target, 0);
		}
		else if (ps == 'b')
		{
			if (moves.side == up)
				ps_rb(target, 0);
			else
				ps_rrb(target, 0);
		}
	}
}

void	push_cheapest(t_stack *src, t_stack *dst)
{
	t_stack *min;
	t_stack	*max;

	if (src->moves.side == both && dst->moves.side != both)
		src->moves.side = dst->moves.side;
	else if (dst->moves.side == both && src->moves.side != both)
		dst->moves.side = src->moves.side;
	if (src->moves.side == dst->moves.side)
	{
		if (src->moves.cost < dst->moves.cost)
			(min = src, max = dst);
		else
			(min = dst, max = src); 
		max->moves.cost -= min->moves.cost;
		duo_rot(min->moves, &(src->list), &(dst->list));
		rot(&(max->list), max->moves, max->id);
	}
	else
		(rot(&(src->list), src->moves, src->id),
			rot(&(dst->list), dst->moves, dst->id));
	ps_pb(&(src->list), &(dst->list), 0);
}
