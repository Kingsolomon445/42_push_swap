/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:27:50 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 15:02:32 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_slist **top_a, t_slist **top_b)
{
	rotate_both(top_a, top_b);
	ft_printf("rr\n");
}

void	rrr(t_slist **top_a, t_slist **top_b)
{
	reverse_rotate_both(top_a, top_b);
	ft_printf("rrr\n");
}

void	ss(t_slist **top_a, t_slist **top_b)
{
	swap_both(top_a, top_b);
	ft_printf("ss\n");
}
