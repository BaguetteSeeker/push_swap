/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:49:09 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/16 20:54:35 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a) : shift up all elements of stack a by 1. 
// The first element becomes the last one.
void	ps_ra(t_stack **a, int output)
{
	t_stack	*tmp;

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
void	ps_rb(t_stack **b, int output)
{
	t_stack	*tmp;

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
void	ps_rr(t_stack **a, t_stack **b, int output)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ps_ra(a, 1);
	ps_rb(b, 1);
	if (output == 0)
		write(1, "rr\n", 3);
}

// rra (reverse rotate a) : shift down all elements of stack a by 1. 
// The last element becomes the first one.
void	ps_rra(t_stack **a, int output)
{
	t_stack	*tmp;
	int		i;

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
void	ps_rrb(t_stack **b, int output)
{
	t_stack	*tmp;
	int		i;

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
void	ps_rrr(t_stack **a, t_stack **b, int output)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ps_rra(a, 1);
	ps_rrb(b, 1);
	if (output == 0)
		write(1, "rrr\n", 4);
}
