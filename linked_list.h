/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:30:59 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/03 17:36:01 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include "stdlib.h"

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}	t_stack;

# ifndef LL_TYP
#  define LL_TYP t_stack
# endif
#endif