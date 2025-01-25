/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premade_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:23:23 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/25 22:58:58 by epinaud          ###   ########.fr       */
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
		eval_rots(get_dest((*stk_b)->nbr, *stk_a, OBVERSE), stks->a.size, &dst);
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
