/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:16:43 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/20 04:24:06 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a) : swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
void	ps_sa(t_stack **a, int output)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (output == 0)
		write(1, "sa\n", 3);
}

// sb (swap b) : swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
void	ps_sb(t_stack **b, int output)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (output == 0)
		write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.
void	ps_ss(t_stack **a, t_stack **b, int output)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (output == 0)
		write(1, "ss\n", 3);
}
