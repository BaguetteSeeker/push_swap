/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/14 04:19:43 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_err(char *msg)
{
	(void)msg;
	ft_putendl_fd("Error", 1);
	// if (errno)
	// 	perror(msg);
	// if(msg[0])
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}

static void	lst_put(t_stack *lst)
{
	ft_putstr_fd("New list has nbr : ", 1);
	ft_putnbr_fd(lst->nbr, 1);
	ft_putendl_fd("", 1);
}

void initial_push(t_stack **stack_a, t_stack **stack_b)
{
	ps_pb(stack_a, stack_b, 1);
	ps_pb(stack_a, stack_b, 1);
}

//Evals & returns sort cost for given nbr in source stack
void	eval_rots(size_t pos, size_t lstsiz, size_t *move, size_t *cost)
{
	size_t	mid_threshold;

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

//else if case increasingly starts lacking in optimization as stacks vary in size from one another 
size_t	move_cost(t_sort mv)
{
	if (mv.out_move == both || mv.in_move == both || mv.out_move == mv.in_move)
		return (ft_maxint(mv.out_cost, mv.in_cost) + PUSH_COST);
	else
		return (mv.out_cost + mv.in_cost + PUSH_COST);
}

t_sort	fetch_cheapest(t_stack *src, t_stack *dst, size_t src_siz, size_t dst_siz)
{
	t_sort	moves;
	t_sort	cheapest;
	
	eval_rots(get_pos(src->nbr, src), src_siz, &(moves.out_move), &(moves.out_cost));
	eval_rots(get_dest(src->nbr, dst), dst_siz, &(moves.in_move), &(moves.in_cost));
	moves.full_cost = move_cost(moves);
	cheapest = moves;
	src = src->next;
	while (src)
	{
		eval_rots(get_pos(src->nbr, src), src_siz, &(moves.out_move), &(moves.out_cost));
		eval_rots(get_dest(src->nbr, dst), dst_siz, &(moves.in_move), &(moves.in_cost));
		moves.full_cost = move_cost(moves);
		if (moves.full_cost < cheapest.full_cost)
		{
			ft_printf("New cheapest is %d\n", src->nbr);
			cheapest = moves;
		}
		src = src->next;
	}
	return (cheapest);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack	**start_a;
	t_sort	moves;
	size_t	lstsiz_a;
	size_t	lstsiz_b;
	(void)stack_b;
	(void)lstsiz_a;
	(void)lstsiz_b;

	ft_putendl_fd("Show lst vals before sort", 1);
	ft_lstiter(*stack_a, &lst_put);

	t_stack	stack_b01 = (t_stack){.nbr = 11, .next = NULL};
	t_stack	stack_b02 = (t_stack){.nbr = 7, .next = &stack_b01};
	t_stack	stack_b03 = (t_stack){.nbr = 3, .next = &stack_b02};
	t_stack	stack_b04 = (t_stack){.nbr = 15, .next = &stack_b03};
	t_stack	stack_b05 = (t_stack){.nbr = 13, .next = &stack_b04};
	t_stack	stack_b06 = (t_stack){.nbr = 12, .next = &stack_b05};
	
	//initial_push(stack_a, stack_b);
	// lstsiz_b = INITIAL_STACKSIZ;
	lstsiz_a = ft_lstsize(*stack_a);
	
	eval_rots(get_pos(3, &stack_b06), ft_lstsize(&stack_b06), &(moves.out_move), &(moves.out_cost));
	eval_rots(get_dest(3, *stack_a), lstsiz_a, &(moves.in_move), &(moves.in_cost));
	ft_printf("For 3, \nOut cost is %u && Out move %u\n", moves.out_cost, moves.out_move);
	ft_printf("In cost is %u and prefered move is %u\n", moves.in_cost, moves.in_move);
	ft_printf("Cheapest in stack a to b has %d\n", fetch_cheapest(*stack_a, &stack_b06, lstsiz_a, ft_lstsize(&stack_b06)).full_cost);
	// while (lstsiz_a > 3)
	// {
	// 	// 	ps_pb(stack_a, stack_b, 0);

	// 	//cheapest = find_cheapest(*stack_a);
	// 	//Find cheapest cost elm
	// 	//Rotate it to the closest edges of its stack (optimise through find_optimum_exit)
	// 	//Push ps_pb()
	// 	//Find optimum slot : if nbr is MAX or MIN in dst stack -> pre-sort dest stack and put nbr at the top
	// 	//Get the closest edge in dst stack and bulk rotate said stack till 

	// 	lstsiz_a--;
	// 	lstsiz_b++;
	// }
	// sort_three(stack_a);
	//  	sort_five(stack_a);
	ft_putendl_fd("Show lst vals after sort", 1);
	ft_lstiter(*stack_a, &lst_put);
}

int	main(int argc, char *argv[])
{
	//t_pswap	stacks;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	// stack_a = ft_lstnew(&(t_stack){.next = NULL, .prev = NULL, .nbr = 5, .index = 0});
	// stack_c = ft_lstnew(&(t_stack){.next = NULL, .nbr = 1, .index = 0});
	// 	ft_printf("Stack c nbr is %d\n", stack_c->nbr);
	// stack_b = ft_lstnew(&(t_stack){.next = (struct s_stack *)stack_c, .nbr = 2, .index = 0});
	// printf("Stack c ptr is %p and its ptr from stk b is %p\n", stack_c, stack_b->next);
	// stack_b->next = (struct s_stack *)stack_c;
	// 	printf("Stack c ptr is %p and its ptr from stk b is %p\n", stack_c, stack_b->next);
	if (argc < 2)
		return(ft_putendl_fd("Invalid argument count", 1), 1);	
	if (parse_args(argc, ++argv, &stack_a))
		exit(1);
	if (!lst_orderchk(stack_a))
		sort_list(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &lst_wipe);
}