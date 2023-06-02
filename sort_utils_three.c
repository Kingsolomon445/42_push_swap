/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:19:21 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 14:43:25 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Checks for which requires less moves and perform either rotate or reverse
rotate.*/
void	ra_or_rra_action(int r_moves, int rr_moves, t_slist **top)
{
	if (r_moves < rr_moves)
	{
		while (--r_moves > 0)
			ra(top);
	}
	else
	{
		while (--rr_moves > 0)
			rra(top);
	}
}

void	rb_or_rrb_action(int r_moves, int rr_moves, t_slist **top)
{
	if (r_moves < rr_moves)
	{
		while (--r_moves > 0)
			rb(top);
	}
	else
	{
		while (--rr_moves > 0)
			rrb(top);
	}
}

void	rr_action(
	int ra_moves, int rb_moves, t_slist **top_a, t_slist **top_b)
{
	ra_moves--;
	rb_moves--;
	while (ra_moves > 0 && rb_moves > 0)
	{
		rr(top_a, top_b);
		ra_moves--;
		rb_moves--;
	}
	ra_moves++;
	rb_moves++;
	while (--ra_moves > 0)
		ra(top_a);
	while (--rb_moves > 0)
		rb(top_b);
}

void	rrr_action(
int rra_moves, int rrb_moves,
t_slist **top_a, t_slist **top_b)
{
	rra_moves--;
	rrb_moves--;
	while (rra_moves > 0 && rrb_moves > 0)
	{
		rrr(top_a, top_b);
		rra_moves--;
		rrb_moves--;
	}
	rra_moves++;
	rrb_moves++;
	while (--rra_moves > 0)
		rra(top_a);
	while (--rrb_moves > 0)
		rrb(top_b);
}
