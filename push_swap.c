/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/17 16:44:53 by epinaud          ###   ########.fr       */
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

size_t	out_cost(int nbr, t_stack **stack, size_t *lstsiz)
{
	size_t	pos;
	size_t	cost;

	cost = 1;
	pos = get_pos(nbr, *stack);
	if ((*lstsiz + RR_EXCES_COST) - pos < pos)
		cost += *lstsiz + RR_EXCES_COST;
	else
		cost += pos;
	return (cost);
}

// size_t	in_cost(int nbr, t_stack **stack, size_t *lstsiz)
// {
// 	size_t	mid_threshold;
// 	size_t	cost;

// 	cost = 1;
// 	mid_threshold = *lstsiz / 2;
// 	if (get_pos(nbr, *stack) > mid_threshold)
// 		cost += RR_EXCES_COST;
// 	return (cost);
// }

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	// t_stack	**start_a;
	size_t	lstsiz_a;
	size_t	lstsiz_b;
	(void)stack_b;
	//int		cheapest;
	ft_putendl_fd("Show lst vals before sort", 1);
	ft_lstiter(*stack_a, &lst_put);

	//initial_push(stack_a, stack_b);
	lstsiz_b = INITIAL_STACKSIZ;
	lstsiz_a = ft_lstsize(*stack_a);

	//  	sort_five(stack_a);
	while (lstsiz_a > 3)
	{
		// 	ps_pb(stack_a, stack_b, 0);

		//cheapest = find_cheapest(*stack_a);
		//Find cheapest cost elm
		//Rotate it to the closest edges of its stack (optimise through find_optimum_exit)
		//Push ps_pb()
		//Find optimum slot : if nbr is MAX or MIN in dst stack -> pre-sort dest stack and put nbr at the top
		//Get the closest edge in dst stack and bulk rotate said stack till 

		lstsiz_a--;
		lstsiz_b++;
	}
	sort_three(stack_a);
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