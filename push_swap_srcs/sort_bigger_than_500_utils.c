/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_than_500_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:55:54 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 11:18:32 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	position = find_elem_pos(top_b, smallest);
	if (position == 3)
		sb(top_b);
	else if (position == 2)
		rrb(top_b);
	else
		rb(top_b);
	reverse_sort_three(top_b);
}

int	find_left_chunk(t_slist **top_a, int start_chunk, int end_chunk)
{
	t_slist	*current;
	int		pos;

	current = *top_a;
	pos = 0;
	while (current)
	{
		pos++;
		if (current->map >= start_chunk && current->map <= end_chunk)
			return (pos);
		current = current->next;
	}
	return (-1);
}

int	find_right_chunk(t_slist **top_a, int start_chunk, int end_chunk)
{
	t_slist	*current;
	int		i;
	int		pos;

	current = *top_a;
	pos = -1;
	i = 0;
	while (current)
	{
		i++;
		if (current->map >= start_chunk && current->map <= end_chunk)
			pos = i;
		current = current->next;
	}
	return (pos);
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
		ra_or_rra_action(act->ra_moves, act->rra_moves, top_a);
		rb_or_rrb_action(act->rb_moves, act->rrb_moves, top_b);
	}
	pb(top_a, top_b);
}
