/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:59:23 by ofadahun          #+#    #+#             */
/*   Updated: 2023/05/29 14:46:51 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_slist **top)
{
	t_slist	*tmp;

	if (!(*top))
		return ;
	while ((*top)->next)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
	free(*top);
}

void	print_all(t_slist **top_a)
{
	t_slist	*current_a;

	current_a = *top_a;
	ft_printf("\n");
	ft_printf("Stack A ====   ");
	while (current_a)
	{
		ft_printf("%d (%d)    -> ", current_a->data, current_a->map);
		current_a = current_a->next;
	}
	ft_printf("\n");
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' || \
	*str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	return (res * sign);
}
