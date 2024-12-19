/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/19 20:15:16 by epinaud          ###   ########.fr       */
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

//Evals necessarry rotations & their direction to properly prep the given stack
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

//else if case : Weak cost remains to be implemented in order to solve the growing deoptimization 
//occuring with divergeant rot directions as stack sizes vary more & more in siz from one another
size_t	move_cost(t_sort nbr/* , size_t dst_stacksiz, size_t src_stacksiz */)
{
	if (nbr.src_move == both || nbr.dst_move == both || nbr.src_move == nbr.dst_move)
		return (ft_maxint(nbr.src_cost, nbr.dst_cost) + PUSH_COST);
	// 
	// else if (nbr.src_move != nbr.dst_move)
	// {
	// 	if (nbr.src_cost > (dst_stacksiz - nbr.dst_cost))
	// 		return (nbr.src_cost +  PUSH_COST);
	// 	else if (nbr.dst_cost > (src_stacksiz - nbr.dst_cost))
	// 		return (nbr.dst_cost + PUSH_COST);
	// 	else
	// 		return (nbr.src_cost + nbr.dst_cost + PUSH_COST);
	// }
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
		{
			ft_printf("New cheapest is %d for %d total moves\n", src->nbr, number.full_cost);
			cheapest = number;
		}
		src = src->next;
	}
	ft_putendl_fd("For B stack as follow :", 1);
	ft_lstiter(dst, &lst_put);
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

	t_stack	stack_b01 = (t_stack){.nbr = 12, .next = NULL};
	t_stack	stack_b02 = (t_stack){.nbr = 13, .next = &stack_b01};
	t_stack	stack_b03 = (t_stack){.nbr = 15, .next = &stack_b02};
	t_stack	stack_b04 = (t_stack){.nbr = 3, .next = &stack_b03};
	t_stack	stack_b05 = (t_stack){.nbr = 7, .next = &stack_b04};
	t_stack	stack_b06 = (t_stack){.nbr = 11, .next = &stack_b05};
	
	//initial_push(stack_a, stack_b);
	// lstsiz_b = INITIAL_STACKSIZ;
	lstsiz_a = ft_lstsize(*stack_a);
	
	eval_rots(get_pos(3, &stack_b06), ft_lstsize(&stack_b06), &(moves.src_move), &(moves.src_cost));
	eval_rots(get_dest(3, *stack_a), lstsiz_a, &(moves.dst_move), &(moves.dst_cost));
	// ft_printf("For 3, \nOut cost is %u && Out move %u\n", moves.src_cost, moves.src_move);
	// ft_printf("In cost is %u and prefered move is %u\n", moves.dst_cost, moves.dst_move);
	ft_printf("Cheapest in stack a to b has %d\n", fetch_cheapest(*stack_a, &stack_b06, lstsiz_a,
		ft_lstsize(&stack_b06)).full_cost);
	// while (lstsiz_a > 3)
	// {
	// 	//cheapest = find_cheapest(*stack_a);
	// 	// 	ps_pb(stack_a, stack_b, cheapest.pos);
	// 	//Push ps_pb()
	// 	lstsiz_a--;
	// 	lstsiz_b++;
	// }
	// sort_three(stack_a);
	
	ft_putendl_fd("Show lst vals after sort", 1);
	ft_lstiter(*stack_a, &lst_put);
}

int	main(int argc, char *argv[])
{
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