/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/20 23:19:09 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	lst_put(t_stack *lst)
// {
// 	ft_putstr_fd("Stack member has nbr : ", 1);
// 	ft_putnbr_fd(lst->nbr, 1, 0);
// 	ft_putendl_fd("", 1);
// }

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	ps_pb(stack_a, stack_b, 0);
	ps_pb(stack_a, stack_b, 0);
	if ((*stack_b)->nbr < (*stack_b)->next->nbr)
		ps_sb(stack_b, 0);
}

//Evals necessarry rotations & their direction to properly prep the given stack
void	eval_rots(size_t pos, size_t lstsiz, size_t *move, size_t *cost)
{
	size_t	mid_threshold;

	if (pos == 0)
	{
		*move = both;
		*cost = 0;
		return ;
	}
	mid_threshold = lstsiz / 2;
	if (pos == mid_threshold)
	{
		*move = both;
		*cost = lstsiz - pos;
	}
	else if (pos > mid_threshold)
	{
		*move = down;
		*cost = lstsiz - pos;
	}
	else
	{
		*move = up;
		*cost = pos;
	}
}

//Strong stack opt. : remains to be implemented in order to solve the growing deoptimization 
//occuring with divergeant rot directions as stack sizes vary more & more in siz from one another
size_t	move_cost(t_sort nbr)
{
	if (nbr.src_move == both || nbr.dst_move == both || nbr.src_move == nbr.dst_move)
		return (ft_maxint(nbr.src_cost, nbr.dst_cost) + PUSH_COST);
	else
		return (nbr.src_cost + nbr.dst_cost + PUSH_COST);
}

t_sort	fetch_cheapest(t_stack *src, t_stack *dst,
	size_t src_siz, size_t dst_siz)
{
	t_sort	number;
	t_sort	cheapest;
	t_stack	*src_head;

	src_head = src;
	cheapest = (t_sort){0};
	cheapest.pos = -1;
	while (src)
	{
		number.pos = get_pos(src->nbr, src_head);
		eval_rots(number.pos, src_siz, &(number.src_move), &(number.src_cost));
		eval_rots(get_dest(src->nbr, dst), dst_siz,
			&(number.dst_move), &(number.dst_cost));
		number.full_cost = move_cost(number);
		if (number.full_cost < cheapest.full_cost || cheapest.pos == -1)
			cheapest = number;
		src = src->next;
	}
	return (cheapest);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	void	(*psptr)(t_stack **, int);
	t_sort	cheapest;
	t_sort	moves;
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
	
	eval_rots(get_pos(lst_max(*stack_b), *stack_b), lstsiz_b, &(moves.src_move), &(moves.src_cost));
	if (moves.src_move == up)
		psptr = &ps_rb;
	else
		psptr = &ps_rrb;
	while (moves.src_cost-- != 0)
		psptr(stack_b, 0);	
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
	// ft_putendl_fd("Show lst vals before sort", 1);
	// ft_lstiter(*stack_a, &lst_put);
	if (!lst_orderchk(stack_a))
		sort_list(&stack_a, &stack_b);
	// ft_putendl_fd("Show lst vals after sort\n A stack is:", 1);
	// ft_lstiter(stack_a, &lst_put);
	// ft_putendl_fd("\n\nB Stack has :", 1);
	// ft_lstiter(stack_b, &lst_put);
	ft_lstclear(&stack_a, &lst_wipe);
}
