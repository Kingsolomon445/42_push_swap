/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:41:40 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 14:43:39 by ofadahun         ###   ########.fr       */
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
	position = get_position(top_b, smallest);
	if (position == 3)
		sb(top_b);
	else if (position == 2)
		rrb(top_b);
	else
		rb(top_b);
	reverse_sort_three(top_b);
}
