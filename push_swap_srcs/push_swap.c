/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:46:01 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 13:05:46 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Sort three elemens using the minimum operations required
Operation to be used depend on the position of the largest element
*/

void	sort_three(t_slist **top_a)
{
	int	pos;

	pos = find_elem_pos(top_a, find_largest(top_a));
	if (pos == 3)
		sa(top_a);
	else if (pos == 2)
		rra(top_a);
	else
		ra(top_a);
	if (!(is_in_order(top_a)))
		sort_three(top_a);
}

/*
Pushed the two smallest to stack b
Sorts the reamining three in stack a
Push the two smallest back to stack a
*/
void	sort_small_stack(t_slist **top_a)
{
	int		pos;
	int		ra_moves;
	int		rra_moves;
	t_slist	*top_b;

	top_b = NULL;
	if (lstsize(*top_a) == 2)
	{
		sa(top_a);
		return ;
	}
	while (lstsize(*top_a) > 3)
	{
		pos = find_elem_pos(top_a, find_smallest(top_a));
		ra_moves = pos;
		rra_moves = lstsize(*top_a) - pos + 2;
		ra_or_rra_action(ra_moves, rra_moves, top_a);
		if (is_in_order(top_a) && is_empty(&top_b))
			return ;
		pb(top_a, &top_b);
	}
	sort_three(top_a);
	while (!is_empty(&top_b))
		pa(top_a, &top_b);
}

int	main(int argc, char *argv[])
{
	t_slist	*head_a;
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	head_a = NULL;
	while (argv[++i])
	{
		if (!eval_args(&head_a, argv[i]))
			return (free_all(&head_a), write(2, "Error\n", 6), 1);
	}
	if (is_empty(&head_a) || check_for_duplicates(&head_a))
		return (free_all(&head_a), write(2, "Error\n", 6), 1);
	if (is_in_order(&head_a))
		return (free_all(&head_a), 0);
	map_lst(&head_a);
	if (lstsize(head_a) == 3)
		sort_three(&head_a);
	else if (lstsize(head_a) <= 5)
		sort_small_stack(&head_a);
	else if (lstsize(head_a) <= 500)
		sort(&head_a);
	else
		sort_very_big_stack(&head_a);
	return (free_all(&head_a), 0);
}
