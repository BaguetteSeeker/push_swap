/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:19:11 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/21 19:36:15 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_err(char *msg, char **args, char **nbrs, t_stack **stack)
{
	(void)msg;
	ft_putendl_fd("Error", 1);
	if (ft_strchr(*args, ' '))
		ft_clean_memtree(nbrs);
	ft_lstclear(stack, &lst_wipe);
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}

void	lst_wipe(t_stack *lst)
{
	lst->nbr = 0;
}

static int	check_dup(char *strnum, char **args)
{
	while (*args)
	{
		if (!ft_strcmp(*args, strnum))
			return (1);
		args++;
	}
	return (0);
}

//Take + signs into account ??
static int	check_arg(char **args)
{
	size_t		nlen;
	size_t		slen;
	long long	nbr;

	slen = ft_strlen(*args);
	nbr = ft_atoi(*args);
	nlen = ft_nbrlen(nbr);
	if (slen != nlen)
		return (1);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	if (check_dup(*args, args + 1))
		return (1);
	return (0);
}

int	parse_args(int argc, char **args, t_stack **stack_a)
{
	char	**numstrlst;
	t_stack	*node;
	size_t	i;

	numstrlst = NULL;
	if (argc > 2 && ft_strchr(*args, ' '))
		put_err("", args, NULL, stack_a);
	else if (!ft_strchr(*args, ' '))
		numstrlst = args;
	else if (ft_strchr(*args, ' '))
		numstrlst = ft_split(*args, ' ');
	i = 0;
	while (numstrlst[i])
	{
		if (check_arg(&numstrlst[i]))
			put_err("", args, numstrlst, stack_a);
		node = ft_lstnew(&(t_stack){ft_atoi(numstrlst[i++]), NULL});
		if (!node)
			put_err("", args, numstrlst, stack_a);
		else
			ft_lstadd_back(stack_a, node);
	}
	if (ft_strchr(*args, ' '))
		ft_clean_memtree(numstrlst);
	return (0);
}
