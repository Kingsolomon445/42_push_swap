/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:44 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:26:30 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*head;

	head = NULL;
	while (lst)
	{
		if (lst->content == NULL)
			ft_lstclear(&lst, del);
		current = ft_lstnew(f(lst->content));
		ft_lstadd_back(&head, current);
		lst = lst->next;
	}
	return (head);
}
