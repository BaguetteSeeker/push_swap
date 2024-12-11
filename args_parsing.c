/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:19:11 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/11 22:03:04 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("Slen is %u & nlen is %u \n For str %s & num %d\n",
			slen, nlen, *args, nbr);
	if (nbr < INT_MIN || nbr > INT_MAX)
		put_err("INT overflow within provided values\n");
	if (check_dup(*args, args + 1))
		ft_printf("%s has dupplicate \n", *args);
	return (0);
}

int	parse_args(int argc, char **args, t_stack **stack_a)
{
	char	**numstrlst;
	t_stack	*node;
	size_t	i;

	if (argc > 2 || !ft_strchr(*args, ' '))
		numstrlst = args;
	else
		numstrlst = ft_split(*args, ' ');
	i = 0;
	while (numstrlst[i])
	{
		if (check_arg(&numstrlst[i]))
			return (ft_clean_memtree(numstrlst), 1);
		node = ft_lstnew(&(t_stack){ft_atoi(numstrlst[i++]), NULL});
		if (!node)
			ft_lstclear(stack_a, &lst_wipe);
		else
			ft_lstadd_back(stack_a, node);
	}
	if (argc == 2)
		free(ft_clean_memtree(numstrlst));
	return (0);
}
