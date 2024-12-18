/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:28:34 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/18 12:41:25 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duo_rot(size_t direction, size_t cost, t_stack **a, t_stack **b)
{
	while (cost-- != 0)
	{
		if (direction == 0)
			ps_rr(a, b, 0);
		else if (direction == 1)
			ps_rrr(a, b, 0);
	}
}

void	rot(t_stack **target, size_t cost, size_t direction, char ps)
{
	while (cost-- != 0)
	{
		if (ps == 'a')
		{
			if (direction == 0)
				ps_ra(target, 0);
			else if (direction == 1)
				ps_rra(target, 0);
		}
		else if (ps == 'b')
		{
			if (direction == 0)
				ps_rb(target, 0);
			else if (direction == 1)
				ps_rrb(target, 0);
		}
	}
}

void	push_cheapest(t_sort nbr, t_stack **src_stk, t_stack **dst_stk)
{
	if (nbr.src_move == both || nbr.dst_move == both)
	{
		if (ft_maxint(nbr.src_cost, nbr.dst_cost) == (int)nbr.src_cost)
			nbr.dst_move = nbr.src_move;
		else
			nbr.src_move = nbr.dst_move;
		if (nbr.src_move == both && nbr.dst_move == both)
			nbr = (t_sort){.src_move = both, .dst_move = both,
				.src_cost = nbr.src_cost, .dst_cost = nbr.dst_cost};
	}
	if (nbr.src_move == nbr.dst_move)
	{
		if (nbr.src_cost < nbr.dst_cost)
			(duo_rot(nbr.src_move, nbr.src_cost, src_stk, dst_stk),
				rot(dst_stk, nbr.dst_cost - nbr.src_cost, nbr.dst_move, 'b'));
		else if (nbr.dst_cost < nbr.src_cost)
			(duo_rot(nbr.dst_move, nbr.dst_cost, dst_stk, src_stk),
				rot(src_stk, nbr.src_cost - nbr.dst_cost, nbr.src_move, 'a'));
	}
	else
		(rot(src_stk, nbr.src_cost, nbr.src_move, 'a'),
			rot(dst_stk, nbr.dst_cost, nbr.dst_move, 'b'));
	ps_pb(src_stk, dst_stk, 0);
}
