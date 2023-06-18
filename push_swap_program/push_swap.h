/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:47:11 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 11:19:41 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct ls_list
{
	int				data;
	int				map;
	struct ls_list	*next;
}	t_slist;

typedef struct act_list
{
	int	ra_moves;
	int	rb_moves;
	int	rra_moves;
	int	rrb_moves;
	int	total_moves;
	int	chunk_pos_left;
	int	chunk_pos_right;
}	t_actlist;

void	free_arg_split(char **arg_split);
int		eval_args(t_slist **top, char *arg);
int		check_for_duplicates(t_slist **top);
long	ft_atol(const char *str);
void	map_lst(t_slist **top_a);
void	free_arg_split(char **arg_split);
int		max(int nbr1, int nbr2);
int		min(int nbr1, int nbr2);
void	do_if_alloc_fails(t_slist **top_a, t_slist **top_b);

void	lstadd_front(t_slist **lst, t_slist *new);
void	lstadd_back(t_slist **lst, t_slist *new);
void	lstremove_back(t_slist **top);
t_slist	*lstnew(int data);
int		lstsize(t_slist *lst);
t_slist	*lstlast(t_slist *lst);

void	swap(t_slist **top);
void	push(t_slist **top_first, t_slist **top_second);
void	rotate(t_slist **top);
void	reverse_rotate(t_slist **top);
void	swap_both(t_slist **top_a, t_slist **top_b);
void	rotate_both(t_slist **top_a, t_slist **top_b);
void	reverse_rotate_both(t_slist **top_a, t_slist **top_b);

void	pa(t_slist **top_a, t_slist **top_b);
void	pb(t_slist **top_a, t_slist **top_b);
void	ra(t_slist **top);
void	rb(t_slist **top);
void	rra(t_slist **top);
void	rrb(t_slist **top);
void	sa(t_slist **top);
void	sb(t_slist **top);
void	rr(t_slist **top_a, t_slist **top_b);
void	rrr(t_slist **top_a, t_slist **top_b);
void	ss(t_slist **top_a, t_slist **top_b);

int		is_empty(t_slist **top);
int		is_in_order(t_slist **top_a);
int		is_in_reverse_order(t_slist **top_a);
void	reverse_sort_three(t_slist **top_b);
int		find_left_chunk(t_slist **top_a, int start_chunk, int end_chunk);
int		find_right_chunk(t_slist **top_a, int start_chunk, int end_chunk);
void	perform_moves(t_slist **top_a, t_slist **top_b, t_actlist *act);

void	free_all(t_slist **top);
void	print_all(t_slist **top_a);

int		find_largest(t_slist **top);
int		find_smallest(t_slist **top);
int		find_elem_pos(t_slist **top, int elem);

void	sort_very_big_stack(t_slist **top_a);
void	sort_three(t_slist **top_a);
void	sort(t_slist **top_a);
int		calculate_moves(int ra_moves, int rb_moves, \
int rra_moves, int rrb_moves);
void	make_moves(t_actlist act, t_slist **top_a, t_slist **top_b);
void	push_from_b_to_a(t_slist **top_a, t_slist **top_b);
void	ra_or_rra_action(int r_moves, int rr_moves, t_slist **top);
void	rb_or_rrb_action(int r_moves, int rr_moves, t_slist **top);
void	rr_action(int ra_moves, int rb_moves, t_slist **top_a, t_slist **top_b);
void	rrr_action(\
	int rra_moves, int rrb_moves, t_slist **top_a, t_slist **top_b);

#endif //PUSH_SWAP_H