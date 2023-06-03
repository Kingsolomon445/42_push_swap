/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_than_500.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:53:16 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 11:18:25 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunks_size(t_slist **top)
{
	int	size;
	int	chunks;

	size = lstsize(*top);
	if (size >= 10000)
		chunks = 100 + (size / 5000 * 6);
	if (size >= 3000)
		chunks = 30;
	else if (size >= 1000)
		chunks = 18;
	else if (size >= 500)
		chunks = 13;
	else if (size >= 300)
		chunks = 10;
	else if (size >= 150)
		chunks = 8;
	else if (size >= 50)
		chunks = 6;
	else if (size >= 20)
		chunks = 4;
	else
		chunks = 1;
	return (chunks);
}

static void	customized_small_elem_sort(t_slist **top_a, t_slist **top_b)
{
	int		smallest_position;
	int		to_rotate;
	int		to_reverse_rotate;

	while (!is_in_order(top_a) && lstsize(*top_a) > 3)
	{
		smallest_position = find_elem_pos(top_a, find_smallest(top_a));
		to_rotate = smallest_position - 0;
		to_reverse_rotate = lstsize(*top_a) - smallest_position + 2;
		ra_or_rra_action(to_rotate, to_reverse_rotate, top_a);
		if (is_in_order(top_a))
			return ;
		pb(top_a, top_b);
	}
	if (!is_in_order(top_a))
		sort_three(top_a);
}

static void	push_back_to_a(t_slist **top_a, t_slist **top_b)
{
	int	largest_pos;
	int	r_moves;
	int	rr_moves;

	while (!(is_in_reverse_order(top_b)) && lstsize(*top_b) > 3)
	{
		largest_pos = find_elem_pos(top_b, find_largest(top_b));
		if (largest_pos == 2)
			sb(top_b);
		else if (largest_pos != 1)
		{
			r_moves = largest_pos;
			rr_moves = lstsize(*top_b) - largest_pos + 2;
			if (r_moves < rr_moves)
				r_moves -= 1;
			rb_or_rrb_action(r_moves, rr_moves, top_b);
			if (r_moves < rr_moves)
				sb(top_b);
		}
		pa(top_a, top_b);
	}
	if (lstsize(*top_b) == 3)
		reverse_sort_three(top_b);
	while (!(is_empty(top_b)))
		pa(top_a, top_b);
}

/*
Move the current chunks from a to b
Looking for the element that require the least rotate/reverse rotate/
rotate both or reverse rotate both
moves from a and moves to top then pushes to b*/

static void	move_chunk_from_a_to_b(
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
			ra_or_rra_action(act->ra_moves, act->rra_moves, top_a);
			pb(top_a, top_b);
			continue ;
		}
		act->rb_moves = find_elem_pos(top_b, find_largest(top_b));
		act->rrb_moves = lstsize(*top_b) - find_elem_pos(\
		top_b, find_largest(top_b)) + 2;
		perform_moves(top_a, top_b, act);
	}
	free(act);
}

void	sort_very_big_stack(t_slist **top_a)
{
	int		start_chunk;
	int		end_chunk;
	int		one_chunkth;
	int		size;
	t_slist	*top_b;

	top_b = NULL;
	start_chunk = 1;
	size = lstsize(*top_a);
	end_chunk = lstsize(*top_a) / get_chunks_size(top_a);
	one_chunkth = end_chunk;
	while (lstsize(*top_a) > 10 && !is_in_order(top_a))
	{
		if (end_chunk >= size - 9)
			end_chunk = size - 10;
		move_chunk_from_a_to_b(top_a, &top_b, start_chunk, end_chunk);
		start_chunk = end_chunk + 1;
		end_chunk += one_chunkth;
	}
	customized_small_elem_sort(top_a, &top_b);
	push_back_to_a(top_a, &top_b);
}
