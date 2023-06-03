/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:04:57 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 12:26:36 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_if_alloc_fails(t_slist **top_a, t_slist **top_b)
{
	free_all(top_a);
	free_all(top_b);
	exit(EXIT_FAILURE);
}

int	is_empty(t_slist **top)
{
	if (!(*top))
		return (1);
	return (0);
}

int	is_in_order(t_slist **top_a)
{
	t_slist	*current;

	current = *top_a;
	if (!current)
		return (0);
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

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