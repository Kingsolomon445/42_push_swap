/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:39:52 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 10:32:36 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_largest(t_slist **top)
{
	int		largest;
	t_slist	*current;

	largest = -2147483646;
	current = *top;
	while (current)
	{
		if (current->map > largest)
			largest = current->map;
		current = current->next;
	}
	return (largest);
}

int	find_smallest(t_slist **top)
{
	int		smallest;
	t_slist	*current;

	current = *top;
	smallest = 2147483647;
	while (current)
	{
		if (current->map < smallest)
			smallest = current->map;
		current = current->next;
	}
	return (smallest);
}

int	find_elem_pos(t_slist **top, int elem)
{
	t_slist	*current;
	int		pos;

	current = *top;
	pos = 0;
	while (current)
	{
		pos++;
		if (current->map == elem)
			break ;
		current = current->next;
	}
	return (pos);
}
