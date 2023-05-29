/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:39:12 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/29 14:52:49 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_largest(t_slist **top_a)
{
	int		largest;
	t_slist	*current;

	largest = -2147483646;
	current = *top_a;
	while (current)
	{
		if (current->data > largest)
			largest = current->data;
		current = current->next;
	}
	return (largest);
}

int	find_smallest(t_slist **top_b)
{
	int		smallest;
	t_slist	*current;

	current = *top_b;
	smallest = 2147483646;
	while (current)
	{
		if (current->data < smallest)
			smallest = current->data;
		current = current->next;
	}
	return (smallest);
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
