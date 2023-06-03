/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:31:22 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 10:31:31 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_moves(int ra_moves, int rb_moves, int rra_moves, int rrb_moves)
{
	int	rr_moves;
	int	rrr_moves;
	int	min_alt;

	rr_moves = max(ra_moves, rb_moves);
	rrr_moves = max(rra_moves, rrb_moves);
	min_alt = min(ra_moves, rb_moves) + min(rra_moves, rrb_moves);
	return (min(min(rr_moves, rrr_moves), min_alt));
}

void	make_moves(t_actlist act, t_slist **top_a, t_slist **top_b)
{
	int	rr_moves;
	int	rrr_moves;
	int	min_alt;

	rr_moves = max(act.ra_moves, act.rb_moves);
	rrr_moves = max(act.rra_moves, act.rrb_moves);
	min_alt = min(act.ra_moves, act.rb_moves) \
	+ min(act.rra_moves, act.rrb_moves);
	if (min(min(rr_moves, rrr_moves), min_alt) == rr_moves)
		rr_action(act.ra_moves, act.rb_moves, top_a, top_b);
	else if (min(min(rr_moves, rrr_moves), min_alt) == rrr_moves)
		rrr_action(act.rra_moves, act.rrb_moves, top_a, top_b);
	else
	{
		ra_or_rra_action(act.ra_moves, act.rra_moves, top_a);
		rb_or_rrb_action(act.rb_moves, act.rrb_moves, top_b);
	}
	pb(top_a, top_b);
}

int	find_closest_bigger(t_slist **top, int map)
{
	int		closest_bigger_elem;
	t_slist	*current;

	closest_bigger_elem = 2147483647;
	current = *top;
	while (current)
	{
		if (current->map > map && current->map < closest_bigger_elem)
			closest_bigger_elem = current->map;
		current = current->next;
	}
	return (closest_bigger_elem);
}

/*
Finds the correct order of top_b_element in stack_a
Correct order being the closest bigger element in stack_a
We are trying to acheive an ascending strcuture in stack_a
At the end , we just rr_or_rra the least elem to the top
*/
void	push_from_b_to_a(t_slist **top_a, t_slist **top_b)
{
	int	closest_bigger_elem;
	int	pos;

	while (!is_empty(top_b))
	{
		closest_bigger_elem = find_closest_bigger(top_a, (*top_b)->map);
		if (closest_bigger_elem != 2147483647)
		{
			pos = find_elem_pos(top_a, closest_bigger_elem);
			ra_or_rra_action(pos, lstsize(*top_a) - pos + 2, top_a);
			pa(top_a, top_b);
		}
		else
		{
			pos = find_elem_pos(top_a, find_largest(top_a));
			ra_or_rra_action(pos, lstsize(*top_a) - pos + 2, top_a);
			pa(top_a, top_b);
			sa(top_a);
		}
	}
	pos = find_elem_pos(top_a, 1);
	ra_or_rra_action(pos, lstsize(*top_a) - pos + 2, top_a);
}
