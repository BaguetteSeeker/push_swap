/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:30:15 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/21 03:04:00 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
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

void	sort_five(t_stack **stk_a, t_stack **stk_b, size_t a_siz)
{
	void	(*psptr)(t_stack **, int);
	t_sort	moves;

	ps_pb(stk_a, stk_b, 0);
	ps_pb(stk_a, stk_b, 0);
	sort_three(stk_a);
	while (*stk_b)
	{
		eval_rots(get_dest_rev((*stk_b)->nbr, *stk_a),
			ft_lstsize(*stk_a), &(moves.dst_move), &(moves.dst_cost));
		if (moves.dst_move == up)
			psptr = &ps_ra;
		else
			psptr = &ps_rra;
		while (moves.dst_cost-- != 0)
			psptr(stk_a, 0);
		ps_pa(stk_a, stk_b, 0);
	}
	prep_stack(stk_a, a_siz, 'a');
}

static void	duo_rot(size_t direction, size_t cost, t_stack **a, t_stack **b)
{
	while (cost-- != 0)
	{
		if (direction == up)
			ps_rr(a, b, 0);
		else
			ps_rrr(a, b, 0);
	}
}

static void	rot(t_stack **target, size_t cost, size_t direction, char ps)
{
	while (cost-- != 0)
	{
		if (ps == 'a')
		{
			if (direction == up)
				ps_ra(target, 0);
			else
				ps_rra(target, 0);
		}
		else if (ps == 'b')
		{
			if (direction == up)
				ps_rb(target, 0);
			else
				ps_rrb(target, 0);
		}
	}
}

// if (nbr.src_move == down && nbr.dst_move == down)
// 	nbr = (t_sort){.src_move = both, .dst_move = both,
// 		.src_cost = nbr.src_cost, .dst_cost = nbr.dst_cost};
void	push_cheapest(t_sort nbr, t_stack **src_stk, t_stack **dst_stk)
{
	if (nbr.src_move == both || nbr.dst_move == both)
	{
		if (ft_maxint(nbr.src_cost, nbr.dst_cost) == (int)nbr.src_cost)
			nbr.dst_move = nbr.src_move;
		else
			nbr.src_move = nbr.dst_move;
	}
	if (nbr.src_move == nbr.dst_move)
	{
		if (nbr.src_cost < nbr.dst_cost)
			(duo_rot(nbr.src_move, nbr.src_cost, src_stk, dst_stk),
				rot(dst_stk, nbr.dst_cost - nbr.src_cost, nbr.dst_move, 'b'));
		else
			(duo_rot(nbr.dst_move, nbr.dst_cost, dst_stk, src_stk),
				rot(src_stk, nbr.src_cost - nbr.dst_cost, nbr.src_move, 'a'));
	}
	else
		(rot(src_stk, nbr.src_cost, nbr.src_move, 'a'),
			rot(dst_stk, nbr.dst_cost, nbr.dst_move, 'b'));
	ps_pb(src_stk, dst_stk, 0);
}
