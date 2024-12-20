/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/21 00:13:03 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_stack(t_stack **stack, size_t size, char ps)
{
	void	(*psptr)(t_stack **, int);
	t_sort	moves;

	eval_rots(get_pos(lst_max(*stack), *stack),
		size, &(moves.src_move), &(moves.src_cost));
	if (ps == 'b')
	{
		if (moves.src_move == up)
			psptr = &ps_rb;
		else
			psptr = &ps_rrb;
		while (moves.src_cost-- != 0)
			psptr(stack, 0);
	}
	else
	{
		if (moves.src_move == up)
			psptr = &ps_ra;
		else
			psptr = &ps_rra;
		while (moves.src_cost-- != 0)
			psptr(stack, 0);
	}
}

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	ps_pb(stack_a, stack_b, 0);
	ps_pb(stack_a, stack_b, 0);
	if ((*stack_b)->nbr < (*stack_b)->next->nbr)
		ps_sb(stack_b, 0);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	t_sort	cheapest;
	size_t	lstsiz_a;
	size_t	lstsiz_b;

	lstsiz_a = ft_lstsize(*stack_a);
	lstsiz_b = ft_lstsize(*stack_b);
	if (lstsiz_a == 3)
		return (sort_three(stack_a));
	else if (lstsiz_a == 5)
		return (sort_five(stack_a, stack_b, lstsiz_a, lstsiz_b));
	initial_push(stack_a, stack_b);
	lstsiz_a -= 2;
	lstsiz_b += 2;
	while (*stack_a)
	{
		cheapest = fetch_cheapest(*stack_a, *stack_b, lstsiz_a, lstsiz_b);
		push_cheapest(cheapest, stack_a, stack_b);
		lstsiz_a--;
		lstsiz_b++;
	}
	prep_stack(stack_b, lstsiz_b, 'b');
	while (*stack_b)
		ps_pa(stack_a, stack_b, 0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (parse_args(argc, ++argv, &stack_a))
		exit(1);
	if (!lst_orderchk(stack_a))
		sort_list(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &lst_wipe);
}
