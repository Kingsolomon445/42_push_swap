/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:39:12 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 10:29:55 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_least_elem(t_slist **top)
{
	int		least_elem;
	t_slist	*current;

	least_elem = INT_MAX;
	current = *top;
	while (current)
	{
		if (current->map < least_elem)
			least_elem = current->map;
		current = current->next;
	}
	return (least_elem);
}

int	find_in_other_stack(t_slist **top, int elem)
{
	t_slist	*current;

	current = *top;
	while (current)
	{
		if (current->map == elem)
			return (1);
		current = current->next;
	}
	return (0);
}

/*
Checks all elems in stack_a and whichever requires the least moves to bring
to the correct position in stack_b is used.
Algorithm for decision: 
if number to be pushed is lesser than all elements in b
	we bring the biggest elem in b to top
	we bring that number to push in a to top
	we push to b
else
	we find b_elem which is immediately lesser to the a_elem
	we bring both to the tops of their respective stacks
	we push to b
*/
t_actlist	find_moves_cost(t_slist **top_b, \
t_slist **top_a, int a_elem, int least_b_elem)
{
	int			pos;
	t_actlist	act;

	if ((a_elem > least_b_elem))
	{
		least_b_elem = a_elem;
		while (--least_b_elem && find_in_other_stack(top_a, least_b_elem))
			continue ;
		pos = find_elem_pos(top_b, least_b_elem);
	}
	else
		pos = find_elem_pos(top_b, find_largest(top_b));
	act.rb_moves = pos;
	act.rrb_moves = lstsize(*top_b) - pos + 2;
	pos = find_elem_pos(top_a, a_elem);
	act.ra_moves = pos;
	act.rra_moves = lstsize(*top_a) - pos + 2;
	act.total_moves = calculate_moves(act.ra_moves, \
	act.rb_moves, act.rra_moves, act.rrb_moves);
	return (act);
}

void	push_from_a_to_b(t_slist **top_a, t_slist **top_b, int *least_b_elem)
{
	int			a_elem;
	t_slist		*current;
	int			prev_total_moves;
	t_actlist	act;

	current = *top_a;
	prev_total_moves = 2147483647;
	while (current)
	{
		act = find_moves_cost(top_b, top_a, current->map, *least_b_elem);
		if (act.total_moves < prev_total_moves)
		{
			prev_total_moves = act.total_moves;
			a_elem = current->map;
			if (prev_total_moves <= 2)
				break ;
		}
		current = current->next;
	}
	act = find_moves_cost(top_b, top_a, a_elem, *least_b_elem);
	if (a_elem < *least_b_elem)
		*least_b_elem = a_elem;
	make_moves(act, top_a, top_b);
}

void	sort(t_slist **top_a)
{
	t_slist	*top_b;
	int		first_push;
	int		least_b_elem;

	first_push = 2;
	top_b = NULL;
	while (--first_push)
		pb(top_a, &top_b);
	least_b_elem = find_least_elem(&top_b);
	while (lstsize(*top_a) > 3)
		push_from_a_to_b(top_a, &top_b, &least_b_elem);
	sort_three(top_a);
	push_from_b_to_a(top_a, &top_b);
}
