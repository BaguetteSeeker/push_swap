/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/15 19:10:28 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_err(char *msg)
{
	(void)msg;
	ft_putendl_fd("Error", 1);
	// if (errno)
	// 	perror(msg);
	if(msg[0])
		ft_putendl_fd(msg, 1);
	// clean_game_memory(solong);
	exit(EXIT_FAILURE);
}

void	lst_wipe(t_stack *lst)
{
	lst->nbr = 0;
	lst->index = 0;
}

void	lst_put(t_stack *lst)
{
	ft_putstr_fd("New list has nbr : ", 1);
	ft_putnbr_fd(lst->nbr, 1);
	ft_putendl_fd("", 1);
}

int	check_dup(char *strnum, char **args)
{
	while (*args)
	{
		if (!ft_strcmp(*args, strnum))
			return (1);
		args++;
	}
	return (0);
}

int	check_arg(char **args)
{
	size_t	nlen;
	size_t	slen;
	long long	nbr;
	
	//Take + signs into account ??
	slen = ft_strlen(*args);
	nbr = ft_atoi(*args);
	nlen = ft_nbrlen(nbr);
	if (slen != nlen)
		ft_printf("Slen is %u & nlen is %u \n For str %s & num %d\n", slen, nlen, *args, nbr);
	if (nbr < INT_MIN || nbr > INT_MAX)
		put_err("INT overflow within provided values\n");
	if (check_dup(*args, args + 1))
		ft_printf("%s has dupplicate \n", *args);
	return (0);
}

int	parse_args(int argc, char **args, t_stack **stack_a)
{
	char	**numstrlst;
	t_stack	*nbr;
	size_t	i;
	
	if (argc > 2)
		numstrlst = args;
	else
		numstrlst = ft_split(args[1], ' ');
	i = 0;
	while (numstrlst[i])
	{
		if (check_arg(&numstrlst[i]))
			return (1);
		nbr = ft_lstnew(&(t_stack){.nbr = ft_atoi(numstrlst[i++])});
		if (!nbr)
			ft_lstclear(stack_a, &lst_wipe);
		else
			ft_lstadd_back(stack_a, nbr);
	}
	if (argc == 2)
		free(numstrlst);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	// t_stack	*stack_b;
	// t_stack	*stack_c;

	stack_a = NULL;
	// stack_a = ft_lstnew(&(t_stack){.next = NULL, .prev = NULL, .nbr = 5, .index = 0});
	// stack_b = ft_lstnew(&(t_stack){.next = NULL, .prev = stack_a, .nbr = 8, .index = 0});
	// stack_c = ft_lstnew(&(t_stack){.next = NULL, .prev = stack_b, .nbr = 2, .index = 0});
	if (argc < 2)
		return(ft_putendl_fd("Invalid argument count", 1), 1);
	// ft_printf("Stacks abc val before sort %p %p %p\n", stack_a->prev, stack_b->prev, stack_c->prev);
	// // ft_swap(&(stack_a->nbr), &(stack_b->nbr));
	// ft_swap((long *)&(stack_a->prev), (long *)&(stack_b->prev));
	// ft_printf("After sort %p %p %p\n", stack_a->prev, stack_b->prev, stack_c->prev);
	
	if (parse_args(argc, ++argv, &stack_a))
		exit(1);
	ft_lstiter(stack_a, &lst_put);
	ft_lstclear(&stack_a, &lst_wipe);
}