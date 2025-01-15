/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:30:59 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/15 02:55:11 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_LIST_H
# define NUMBER_LIST_H
# include "stdlib.h"

typedef struct s_nbrlst
{
	long			nbr;
	struct s_nbrlst	*next;
}	t_nbrlst;

# define LL_TYP t_nbrlst
#endif