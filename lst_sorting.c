/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:30:15 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/17 16:41:52 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	prep_src(t_stack *stack, int nbr, int move_code)
// {
// 	//while
// }

// void	prep_dst(t_stack *stack, int nbr, int move_code)
// {
// 	//while
// }

// void	prep_stack(t_stack *stack, int nbr, int move_code)
// {
// 	//while
// }

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
