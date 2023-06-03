/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:31:41 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:20:14 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!(*lst))
		return ;
	current = (*lst);
	while (current)
	{
		(*lst) = (*lst)->next;//keeping copy of address of next before deleting current node
		ft_lstdelone(current, del);
		current = (*lst);
	}
	(*lst) = NULL;
}
