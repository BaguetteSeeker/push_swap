/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:46:48 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/04 02:17:15 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa (push a) : take the first element at the top of b and 
// put it at the top of a. Do nothing if b is empty.
void	ps_pa(t_nbrlst **a, t_nbrlst **b, int output)
{
	t_nbrlst	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (output == 0)
		write(1, "pa\n", 3);
}

// pb (push b) : take the first element at the top of a and put it 
// at the top of b. Do nothing if a is empty.
void	ps_pb(t_nbrlst **stack_a, t_nbrlst **stack_b, int output)
{
	t_nbrlst	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (output == 0)
		write(1, "pb\n", 3);
}
