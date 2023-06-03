/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:42:38 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 12:11:59 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_both(t_slist **top_a, t_slist **top_b)
{
	rotate(top_a);
	rotate(top_b);
}

void	reverse_rotate_both(t_slist **top_a, t_slist **top_b)
{
	reverse_rotate(top_a);
	reverse_rotate(top_b);
}

void	swap_both(t_slist **top_a, t_slist **top_b)
{
	swap(top_a);
	swap(top_b);
}
