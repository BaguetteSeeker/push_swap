/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:30:59 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/14 02:56:29 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLD_STRUCT_H
# define LLD_STRUCT_H
# include "stdlib.h"

typedef struct s_numset
{
	char			xpm[255];
	void			*img;
	int				imgwdth;
	int				imghght;
	struct s_numset	*next;
}	t_numset;

# ifndef LL_TYP
#  define LL_TYP t_numset
# endif
#endif