/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:42:38 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/22 16:32:46 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_slist **top_a, t_slist **top_b)
{
	rotate(top_a, ' ');
	rotate(top_b, ' ');
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_slist **top_a, t_slist **top_b)
{
	reverse_rotate(top_a, ' ');
	reverse_rotate(top_b, ' ');
	ft_printf("rrr\n");
}

void	swap_both(t_slist **top_a, t_slist **top_b)
{
	swap(top_a, ' ');
	swap(top_b, ' ');
	ft_printf("ss");
}
