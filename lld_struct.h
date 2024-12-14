/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:30:59 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/11 21:17:56 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLD_STRUCT_H
# define LLD_STRUCT_H
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