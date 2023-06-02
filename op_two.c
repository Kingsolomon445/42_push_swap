/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:26:54 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 15:02:22 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_slist **top)
{
	reverse_rotate(top);
	ft_printf("rra\n");
}

void	rrb(t_slist **top)
{
	reverse_rotate(top);
	ft_printf("rrb\n");
}

void	sa(t_slist **top)
{
	swap(top);
	ft_printf("sa\n");
}

void	sb(t_slist **top)
{
	swap(top);
	ft_printf("sb\n");
}
