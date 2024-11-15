/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:08:23 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/14 22:54:53 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define ARGV_START 1

void	ft_swap(long *val1, long *val2);
int		min_array(int arr[], size_t siz);
int		max_array(int arr[], size_t siz);