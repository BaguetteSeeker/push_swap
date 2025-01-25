/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:11:11 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/25 22:53:50 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a) : shift down all elements of stack a by 1. 
// The last element becomes the first one.
void	ps_rra(t_nbrlst **a, int output)
{
	t_nbrlst	*tmp;
	int			i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (output == 0)
		write(1, "rra\n", 4);
}

// rrb (reverse rotate b) : shift down all elements of stack b by 1. 
// The last element becomes the first one.
void	ps_rrb(t_nbrlst **b, int output)
{
	t_nbrlst	*tmp;
	int			i;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (output == 0)
		write(1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void	ps_rrr(t_nbrlst **a, t_nbrlst **b, int output)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ps_rra(a, 1);
	ps_rrb(b, 1);
	if (output == 0)
		write(1, "rrr\n", 4);
}
