/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/10 20:43:52 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_stack(t_stack *stack, char ps)
{
	void	(*psptr)(LL_TYP **, int);
	t_sort	moves;

	moves = (t_sort){0};
	if (ps == 'b')
	{
		eval_rots(get_pos(lst_max(stack->list),
			stack->list), stack->size, &moves);
		if (moves.side == up)
			psptr = &ps_rb;
		else
			psptr = &ps_rrb;
		while (moves.cost-- != 0)
			psptr(&(stack->list), 0);
	}
	else
	{
		eval_rots(get_pos(lst_min(stack->list),
			stack->list), stack->size, &stack->moves);
		if (moves.side == up)
			psptr = &ps_ra;
		else
			psptr = &ps_rra;
		while (moves.cost-- != 0)
			psptr(&(stack->list), 0);
	}
}

int	get_dest_rev(int nbr, t_nbrlst *stack)
{
	int		dest;
	long	spread;
	t_nbrlst	*stk_head;

	dest = 0;
	spread = 0;
	stk_head = stack;
	while (stack)
	{
		if (nbr < stack->nbr)
		{
			if (stack->nbr - nbr < spread || spread == 0)
			{
				spread = stack->nbr - nbr;
				dest = stack->nbr;
			}
		}
		stack = stack->next;
	}
	if (spread == 0)
		return (get_pos(lst_max(stk_head), stk_head) + 1);
	return (get_pos(dest, stk_head));
}

void	initial_push(t_nbrlst **stack_a, t_nbrlst **stack_b)
{
	ps_pb(stack_a, stack_b, 0);
	ps_pb(stack_a, stack_b, 0);
	if ((*stack_b)->nbr < (*stack_b)->next->nbr)
		ps_sb(stack_b, 0);
}

void	sort_list(t_nbrlst **stack_a, t_nbrlst **stack_b, t_stacks *stks)
{
	stks->a.size = ft_lstsize(*stack_a);
	stks->b.size = ft_lstsize(*stack_b);
	if (stks->a.size == 3)
		return (sort_three(stack_a));
	else if (stks->a.size == 5)
		return (sort_five(stack_a, stack_b, stks));
	initial_push(stack_a, stack_b);
	stks->a.size -= 2;
	stks->b.size += 2;
	while (*stack_a)
	{
		fetch_cheapest(&(stks->a), &(stks->b), stks);
		push_cheapest(&(stks->a), &(stks->b));
		stks->a.size--;
		stks->b.size++;
	}
	prep_stack(&(stks->b), 'b');
	while (*stack_b)
		ps_pa(stack_a, stack_b, 0);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	stacks = (t_stacks){0};
	stacks.a.id = 'a';
	stacks.b.id = 'b';
	if (argc < 2)
		return (1);
	if (parse_args(argc, ++argv, &(stacks.a.list)))
		exit(1);
	if (!lst_orderchk(stacks.a.list))
		sort_list(&(stacks.a.list), &(stacks.b.list), &stacks);
	ft_lstclear(&(stacks.a.list), &lst_wipe);
}
