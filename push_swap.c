/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:07:57 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/14 02:39:49 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(char **args)
{
	char	*numstr;
	char	*prevalloc;

	numstr = ft_strjoin(*args, *(args + 1));
	if (!numstr)
		(ft_putendl_fd("Aieaie failed to join args 0", 1), exit(1));
	args += 2;
	while (*args)
	{
		prevalloc = numstr;
		numstr = ft_strjoin(numstr, *args);
		
		if (!numstr)
			(ft_putendl_fd("Aieaie failed to join args 1", 1), free(prevalloc), exit(1));
		free(prevalloc);
		args++;
	}
	return (numstr);
}

int	check_arguments(int argc, char **args)
{
	char	*numstr;
	
	if (argc > 2)
		numstr = join_args(++args);
	else
		numstr = args[1];
	ft_printf("Stringed params : %s\n", numstr);
	free(numstr);
	return (0);
}

int	main(int argc, char *argv[])
{
	// t_list	**stack_a;
	// t_list	**stack_b;

	if (argc < 2)
		return(ft_putendl_fd("Invalid argument count", 1), 1);

	if (check_arguments(argc, argv++))
		exit(1);
}