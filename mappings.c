/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:32:41 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 15:03:19 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_smallest(t_slist **top_b, int previous_smallest)
{
	int		smallest;
	t_slist	*current;

	current = *top_b;
	smallest = 2147483647;
	while (current)
	{
		if (current->data < smallest && current->data > previous_smallest)
			smallest = current->data;
		current = current->next;
	}
	return (smallest);
}

int	get_elem_map(t_slist **top, int data)
{
	t_slist	*current;

	current = *top;
	while (current)
	{
		if (current->data == data)
			break ;
		current = current->next;
	}
	return (current->map);
}

void	map_elem(t_slist **top, int data, int map)
{
	t_slist	*current;

	current = *top;
	while (current)
	{
		if (current->data == data)
		{
			current->map = map;
			return ;
		}
		current = current->next;
	}
}

void	map_lst(t_slist **top_a)
{
	int	size;
	int	map;
	int	cur_smallest;

	size = lstsize(*top_a);
	map = 1;
	cur_smallest = find_smallest(top_a);
	map_elem(top_a, cur_smallest, map);
	while (--size)
	{
		++map;
		cur_smallest = find_next_smallest(top_a, cur_smallest);
		map_elem(top_a, cur_smallest, map);
	}
}
