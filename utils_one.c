/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:51 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 14:40:24 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_slist **top)
{
	t_slist	*tmp;

	if (!(*top))
		return ;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
	tmp = NULL;
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

int	get_position(t_slist **top, int data)
{
	int		pos;
	t_slist	*current;

	pos = 0;
	current = *top;
	while (current)
	{
		pos++;
		if (current->data == data)
			break ;
		current = current->next;
	}
	return (pos);
}

int	get_chunks_size(t_slist **top)
{
	int	size;
	int	chunks;

	size = lstsize(*top);
	if (size >= 10000)
		chunks = 40 + (size / 5000 * 6);
	if (size >= 5000)
		chunks = 40;
	else if (size >= 1000)
		chunks = 18;
	else if (size >= 500)
		chunks = 13;
	else if (size >= 300)
		chunks = 10;
	else if (size >= 150)
		chunks = 8;
	else if (size >= 50)
		chunks = 6;
	else if (size >= 20)
		chunks = 4;
	else
		chunks = 1;
	return (chunks);
}
