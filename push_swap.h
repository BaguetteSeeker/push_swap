/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:08:23 by epinaud           #+#    #+#             */
/*   Updated: 2024/12/20 23:18:11 by epinaud          ###   ########.fr       */
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

enum e_rotation
{
	up,
	down,
	both
};

typedef struct s_pswap
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	size_t	a_siz;
	size_t	b_siz;
}	t_pswap;

typedef struct s_sort
{
	int		pos;
	size_t	src_cost;
	size_t	src_move;
	size_t	dst_cost;
	size_t	dst_move;
	size_t	full_cost;
}		t_sort;

//ALTERNATE DATA STRUCTS FOR FURTHER FACTORIZATION
// typedef struct s_nbrlst
// {
// 	long			nbr;
// 	struct s_stack	*next;
// }	t_nbrlst;

// typedef struct s_sort
// {
// 	size_t	move;
// 	size_t	cost;
// }	t_sort;

// typedef struct s_stack
// {
// 	size_t		size;
// 	t_sort		moves;
// 	t_nbrlst	**nbr;
// }	t_stack;

// typedef struct s_stacks
// {
// 	t_stack	a;
// 	t_stack	b;
// }	t_stacks;

# define INITIAL_STACKSIZ 2
# define NO_COST 0
# define PUSH_COST 1
# define RR_EXCES_COST 1

void	sort_list(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stk_a, t_stack **stk_b, size_t a_siz, size_t b_siz);
int		parse_args(int argc, char **args, t_stack **stack_a);
void	eval_rots(size_t pos, size_t lstsiz, size_t *move, size_t *cost);
t_sort	fetch_cheapest(t_stack *src, t_stack *dst,
			size_t src_siz, size_t dst_siz);
void	push_cheapest(t_sort nbr, t_stack **src_stk, t_stack **dst_stk);
void	ft_swap(long *val1, long *val2);
int		min_array(int arr[], size_t siz);
int		max_array(int arr[], size_t siz);
int		lst_min(t_stack *lst);
int		lst_max(t_stack *lst);
int		get_pos(int nbr, t_stack *stack);
int		get_dest(int nbr, t_stack *stack);
int		lst_orderchk(t_stack *stack);
void	lst_wipe(t_stack *lst);
int		put_err(char *msg, char **args, char **nbr_lst, t_stack **stack);

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
