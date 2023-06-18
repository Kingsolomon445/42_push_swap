/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:22:57 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 12:25:40 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_slist	*lstnew(int data)
{
	t_slist	*head;

	head = (t_slist *)malloc(sizeof(t_slist));
	if (!head)
		return (head);
	head->data = data;
	head->next = NULL;
	return (head);
}

int	lstsize(t_slist *lst)
{
	int		size;
	t_slist	*current;

	if (!lst)
		return (0);
	size = 1;
	current = lst;
	while (current->next)
	{
		current = current->next;
		size++;
	}
	return (size);
}

void	lstadd_back(t_slist **lst, t_slist *new)
{
	t_slist	*current;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
