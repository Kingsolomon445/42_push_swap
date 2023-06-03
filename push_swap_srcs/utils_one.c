/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:51 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 10:33:53 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

void	do_if_alloc_fails(t_slist **top_a, t_slist **top_b)
{
	free_all(top_a);
	free_all(top_b);
	exit(EXIT_FAILURE);
}

int	is_empty(t_slist **top)
{
	if (!(*top))
		return (1);
	return (0);
}

int	is_in_order(t_slist **top_a)
{
	t_slist	*current;

	current = *top_a;
	if (!current)
		return (0);
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
