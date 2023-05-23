/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:32:14 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/23 12:39:59 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_slist **top_first, t_slist **top_second, char stack)
{
	t_slist	*tmp;

	if (!(*top_second))
		return ;
	tmp = *top_second;
	*top_second = (*top_second)->next;
	tmp->next = *top_first;
	*top_first = tmp;
	if (stack == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	swap(t_slist **top, char stack)
{
	t_slist	*tmp;

	if (!(*top) || !((*top)->next))
		return ;
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
	if (stack == 'a')
		ft_printf("sa\n");
	else if (stack == 'b')
		ft_printf("sb\n");
}

void	rotate(t_slist **top, char stack)
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
	if (stack == 'a')
		ft_printf("ra\n");
	else if (stack == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_slist **top, char stack)
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
	if (stack == 'a')
		ft_printf("rra\n");
	else if (stack == 'b')
		ft_printf("rrb\n");
}
