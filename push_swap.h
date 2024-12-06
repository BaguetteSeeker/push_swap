/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:08:23 by epinaud           #+#    #+#             */
/*   Updated: 2024/11/22 18:26:17 by epinaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

# define SA_ID 1
# define SB_ID 2
# define SS_ID 3
# define PA_ID 4
# define PB_ID 5
# define RA_ID 6
# define RB_ID 7
# define RR_ID 8
# define RRA_ID 9
# define RRB_ID 10
# define RRR_ID 11

enum e_moveset
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

typedef struct s_sort
{
	size_t	out_cost;
	size_t	in_cost;
	size_t	out_move;
	size_t	in_move;

}		t_sort;

# define INITIAL_STACKSIZ 2
# define NO_COST 0
# define RR_EXCES_COST 1
# define TOPTOBOT_COST 1

void	sort_list(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
int		parse_args(int argc, char **args, t_stack **stack_a);
void	ft_swap(long *val1, long *val2);
int		min_array(int arr[], size_t siz);
int		max_array(int arr[], size_t siz);
int		lst_min(t_stack *lst);
int		lst_max(t_stack *lst);
int		get_pos(int nbr, t_stack *stack);
int		get_dest(int nbr, t_stack *stack);
int		lst_orderchk(t_stack *stack);
void	lst_wipe(t_stack *lst);
int		put_err(char *msg);

void	ps_pa(t_stack **a, t_stack **b, int output);
void	ps_pb(t_stack **a, t_stack **b, int output);
void	ps_sa(t_stack **a, int output);
void	ps_sb(t_stack **b, int output);
void	ps_ss(t_stack **a, t_stack **b, int output);
void	ps_ra(t_stack **a, int output);
void	ps_rb(t_stack **b, int output);
void	ps_rr(t_stack **a, t_stack **b, int output);
void	ps_rra(t_stack **b, int output);
void	ps_rrb(t_stack **b, int output);
void	ps_rrr(t_stack **a, t_stack **b, int output);
#endif
