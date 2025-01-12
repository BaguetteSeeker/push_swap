/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:30:15 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/10 20:45:24 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_nbrlst **stack)
{
	if ((*stack)->nbr == lst_max(*stack))
	{
		ps_ra(stack, 0);
		if ((*stack)->nbr != lst_min(*stack))
			ps_sa(stack, 0);
	}
	else if ((*stack)->nbr == lst_min(*stack))
	{
		if ((*stack)->next->nbr == lst_max(*stack))
		{
			ps_rra(stack, 0);
			ps_sa(stack, 0);
		}
	}
	else
	{
		if ((*stack)->next->nbr == lst_min(*stack))
			ps_sa(stack, 0);
		else
			ps_rra(stack, 0);
	}
}

void	sort_five(t_nbrlst **stk_a, t_nbrlst **stk_b, t_stacks *stks)
{
	void	(*psptr)(t_nbrlst **, int);
	t_sort	dst;

	ps_pb(stk_a, stk_b, 0);
	ps_pb(stk_a, stk_b, 0);
	stks->a.size -= 2;
	sort_three(stk_a);
	while (*stk_b)
	{
		eval_rots(get_dest_rev((*stk_b)->nbr, *stk_a), stks->a.size, &dst);
		if (dst.side == up)
			psptr = &ps_ra;
		else
			psptr = &ps_rra;
		while (dst.cost-- != 0)
			psptr(stk_a, 0);
		ps_pa(stk_a, stk_b, 0);
		stks->a.size++;
	}
	prep_stack(&(stks->a), 'a');
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
