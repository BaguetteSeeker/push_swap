/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epinaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:08:23 by epinaud           #+#    #+#             */
/*   Updated: 2025/01/10 01:43:09 by epinaud          ###   ########.fr       */
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

// typedef struct s_pswap
// {
// 	t_stack	**stack_a;
// 	t_stack	**stack_b;
// 	size_t	a_siz;
// 	size_t	b_siz;
// }	t_pswap;

// typedef struct s_sort
// {
// 	int		pos;
// 	size_t	src_cost;
// 	size_t	src_move;
// 	size_t	dst_cost;
// 	size_t	dst_move;
// 	size_t	full_cost;
// }		t_sort;

//ALTERNATE DATA STRUCTS FOR FURTHER FACTORIZATION
// typedef struct s_nbrlst
// {
// 	long			nbr;
// 	struct s_nbrlst	*next;
// }	t_nbrlst;

typedef struct s_sort
{
	size_t	side;
	size_t	cost;
}	t_sort;

typedef struct s_stack
{
	char		id;
	size_t		size;
	t_sort		moves;
	t_nbrlst	*list;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
	size_t	cheap_cost;
}	t_stacks;

# define INITIAL_STACKSIZ 2
# define NO_COST 0
# define PUSH_COST 1
# define RR_EXCES_COST 1

void	sort_list(t_nbrlst **stack_a, t_nbrlst **stack_b, t_stacks *stks);
void	sort_three(t_nbrlst **stack);
void	sort_five(t_nbrlst **stk_a, t_nbrlst **stk_b, t_stacks *stks);
int		parse_args(int argc, char **args, t_nbrlst **stack_a);
void	eval_rots(size_t pos, size_t lstsiz, t_sort *moves);
void	fetch_cheapest(t_stack *src, t_stack *dst, t_stacks *stacks);
void	prep_stack(t_stack *stack, char ps);
void	push_cheapest(t_stack *src, t_stack *dst);
void	ft_swap(long *val1, long *val2);
int		min_array(int arr[], size_t siz);
int		max_array(int arr[], size_t siz);
int		lst_min(t_nbrlst *lst);
int		lst_max(t_nbrlst *lst);
int		get_pos(int nbr, t_nbrlst *stack);
int		get_dest(int nbr, t_nbrlst *stack);
int		get_dest_rev(int nbr, t_nbrlst *stack);
int		lst_orderchk(t_nbrlst *stack);
void	lst_wipe(t_nbrlst *lst);
void	lst_put(t_nbrlst *lst);
int		put_err(char *msg, char **args, char **nbr_lst, t_nbrlst **stack);

void	ps_pa(t_nbrlst **a, t_nbrlst **b, int output);
void	ps_pb(t_nbrlst **a, t_nbrlst **b, int output);
void	ps_sa(t_nbrlst **a, int output);
void	ps_sb(t_nbrlst **b, int output);
void	ps_ss(t_nbrlst **a, t_nbrlst **b, int output);
void	ps_ra(t_nbrlst **a, int output);
void	ps_rb(t_nbrlst **b, int output);
void	ps_rr(t_nbrlst **a, t_nbrlst **b, int output);
void	ps_rra(t_nbrlst **b, int output);
void	ps_rrb(t_nbrlst **b, int output);
void	ps_rrr(t_nbrlst **a, t_nbrlst **b, int output);
#endif
