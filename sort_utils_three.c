/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:19:21 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/31 16:56:20 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Checks for which requires less moves and perform either rotate or reverse
rotate.*/
void	r_or_rr_action(
	int r_moves, int rr_moves, t_slist **top, char stack)
{
	if (r_moves < rr_moves)
	{
		while (--r_moves > 0)
			rotate(top, stack);
	}
	else
	{
		while (--rr_moves > 0)
			reverse_rotate(top, stack);
	}
}

void	rr_action(
	int ra_moves, int rb_moves, t_slist **top_a, t_slist **top_b)
{
	ra_moves--;
	rb_moves--;
	while (ra_moves > 0 && rb_moves > 0)
	{
		rotate_both(top_a, top_b);
		ra_moves--;
		rb_moves--;
	}
	ra_moves++;
	rb_moves++;
	while (--ra_moves > 0)
		rotate(top_a, 'a');
	while (--rb_moves > 0)
		rotate(top_b, 'b');
}

void	rrr_action(
	int rra_moves, int rrb_moves,
t_slist **top_a, t_slist **top_b)
{
	rra_moves--;
	rrb_moves--;
	while (rra_moves > 0 && rrb_moves > 0)
	{
		reverse_rotate_both(top_a, top_b);
		rra_moves--;
		rrb_moves--;
	}
	rra_moves++;
	rrb_moves++;
	while (--rra_moves > 0)
		reverse_rotate(top_a, 'a');
	while (--rrb_moves > 0)
		reverse_rotate(top_b, 'b');
}
