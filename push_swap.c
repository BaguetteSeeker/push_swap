/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/25 22:30:33 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_put(t_nbrlst *lst)
{
	ft_putstr_fd("Stack member has nbr : ", 1);
	ft_putnbr_fd(lst->nbr, 1, 0);
	ft_putendl_fd("", 1);
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
	stks->a.size -= INITIAL_STACKSIZ;
	stks->b.size += INITIAL_STACKSIZ;
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
