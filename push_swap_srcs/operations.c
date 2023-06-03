/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:32:14 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 12:11:52 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_slist **top_first, t_slist **top_second)
{
	t_slist	*tmp;

	if (!(*top_second))
		return ;
	tmp = *top_second;
	*top_second = (*top_second)->next;
	tmp->next = *top_first;
	*top_first = tmp;
}

void	swap(t_slist **top)
{
	t_slist	*tmp;

	if (!(*top) || !((*top)->next))
		return ;
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
}

void	rotate(t_slist **top)
{
	t_slist	*tmp;
	t_slist	*current;

	if (!(*top) || !((*top)->next))
		return ;
	tmp = *top;
	*top = (*top)->next;
	tmp->next = NULL;
	current = *top;
	while (current->next)
	{
		current = current->next;
		continue ;
	}
	current->next = tmp;
}

void	reverse_rotate(t_slist **top)
{
	t_slist	*tmp;
	t_slist	*current;

	if (!(*top) || !((*top)->next))
		return ;
	current = *top;
	while (current->next->next)
	{
		current = current->next;
		continue ;
	}
	tmp = current->next;
	current->next = NULL;
	tmp->next = *top;
	*top = tmp;
}
