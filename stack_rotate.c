/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:49:09 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/08 12:29:41 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a) : shift up all elements of stack a by 1. 
// The first element becomes the last one.
void	ps_ra(t_nbrlst **a, int output)
{
	t_nbrlst	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (output == 0)
		write(1, "ra\n", 3);
}

// rb (rotate b) : shift up all elements of stack b by 1. 
// The first element becomes the last one.
void	ps_rb(t_nbrlst **b, int output)
{
	t_nbrlst	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (output == 0)
		write(1, "rb\n", 3);
}

// rr : ra and rb at the same time
void	ps_rr(t_nbrlst **a, t_nbrlst **b, int output)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ps_ra(a, 1);
	ps_rb(b, 1);
	if (output == 0)
		write(1, "rr\n", 3);
}
