/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:39:52 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/31 18:32:43 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_if_alloc_fails(t_slist **top_a, t_slist **top_b)
{
	free_all(top_a);
	free_all(top_b);
	exit(EXIT_FAILURE);
}

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

void	perform_moves(t_slist **top_a, t_slist **top_b, t_actlist *act)
{
	if (act->ra_moves < act->rra_moves && act->rb_moves < act->rrb_moves)
		rr_action(act->ra_moves, act->rb_moves, top_a, top_b);
	else if (act->ra_moves >= act->rra_moves && act->rb_moves >= act->rrb_moves)
		rrr_action(act->rra_moves, act->rrb_moves, top_a, top_b);
	else if ((max(act->ra_moves, act->rb_moves) <= (act->ra_moves + act->\
	rrb_moves)) && (max(act->ra_moves, act->rb_moves) <= \
	(act->rra_moves + act->ra_moves)))
		rr_action(act->ra_moves, act->rb_moves, top_a, top_b);
	else if (max(act->rra_moves, act->rrb_moves) <= act->ra_moves + \
	act->rrb_moves && max(act->rra_moves, act->rrb_moves) <= \
	act->rra_moves + act->ra_moves)
		rrr_action(act->rra_moves, act->rrb_moves, top_a, top_b);
	else
	{
		r_or_rr_action(act->ra_moves, act->rra_moves, top_a, 'a');
		r_or_rr_action(act->rb_moves, act->rrb_moves, top_b, 'b');
	}
	push(top_b, top_a, 'b');
}

/*
Move the current chunks from a to b
Looking for the element that require the least rotate/reverse rotate/
rotate both or reverse rotate both
moves from a and moves to top then pushes to b*/

void	move_chunk_from_a_to_b(
	t_slist **top_a, t_slist **top_b, int start_chunk, int end_chunk)
{
	t_actlist	*act;

	act = (t_actlist *)malloc(sizeof (t_actlist));
	if (!act)
		do_if_alloc_fails(top_a, top_b);
	while (lstsize(*top_a) > 10)
	{
		act->chunk_pos_left = find_left_chunk(top_a, start_chunk, end_chunk);
		act->chunk_pos_right = find_right_chunk(top_a, start_chunk, end_chunk);
		if (act->chunk_pos_left == -1 || act->chunk_pos_right == -1)
			break ;
		act->ra_moves = act->chunk_pos_left - 0;
		act->rra_moves = lstsize(*top_a) - act->chunk_pos_right + 2;
		if (is_empty(top_b) || lstsize(*top_b) < 2)
		{
			r_or_rr_action(act->ra_moves, act->rra_moves, top_a, 'a');
			push(top_b, top_a, 'b');
			continue ;
		}
		act->rb_moves = get_position(top_b, find_largest(top_b)) - 0;
		act->rrb_moves = lstsize(*top_b) - get_position(\
		top_b, find_largest(top_b)) + 2;
		perform_moves(top_a, top_b, act);
	}
	free(act);
}

int	is_in_reverse_order(t_slist **top_a)
{
	t_slist	*current;

	current = *top_a;
	while (current->next)
	{
		if (current->data < current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	reverse_sort_three(t_slist **top_b)
{
	int	smallest;
	int	position;
	
	if ((is_in_reverse_order(top_b)))
		return ;
	smallest = find_smallest(top_b);
	position = get_position(top_b, smallest);
	if (position == 3)
		swap(top_b, 'b');
	else if (position == 2)
		reverse_rotate(top_b, 'b');
	else
		rotate(top_b, 'b');
	reverse_sort_three(top_b);
}
/*
Pushes from stack b to a by finding the largest elem , move to top
Then pushes to stack a*/
void	push_from_b_to_a(t_slist **top_a, t_slist **top_b)
{
	int	largest_pos;
	int	r_moves;
	int	rr_moves;

	while (!(is_in_reverse_order(top_b)) && lstsize(*top_b) > 3)
	{
		largest_pos = get_position(top_b, find_largest(top_b));
		if (largest_pos == 2)
			swap(top_b, 'b');
		else if (largest_pos != 1)
		{
			r_moves = largest_pos;
			rr_moves = lstsize(*top_b) - largest_pos + 2;
			if (r_moves < rr_moves)
				r_moves -= 1;
			r_or_rr_action(r_moves, rr_moves, top_b, 'b');
			if (r_moves < rr_moves)
				swap(top_b, 'b');
		}
		push(top_a, top_b, 'a');
	}
	if (lstsize(*top_b) == 3)
		reverse_sort_three(top_b);
	while (!(is_empty(top_b)))
		push(top_a, top_b, 'a');
}
