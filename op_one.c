/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:20:48 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 10:26:45 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_slist **top_a, t_slist **top_b)
{
	push(top_a, top_b);
	ft_printf("pa\n");
}

void	pb(t_slist **top_a, t_slist **top_b)
{
	push(top_b, top_a);
	ft_printf("pb\n");
}

void	ra(t_slist **top)
{
	rotate(top);
	ft_printf("ra\n");
}

void	rb(t_slist **top)
{
	rotate(top);
	ft_printf("rb\n");
}
