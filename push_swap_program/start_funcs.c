/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:55:43 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/03 12:11:45 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arg_split(char **arg_split)
{
	int	i;

	i = 0;
	if (!arg_split)
		return ;
	while (*(i + arg_split))
	{
		free(*(i + arg_split));
		*(i + arg_split) = NULL;
		i++;
	}
	free(arg_split);
	arg_split = NULL;
}

int	check_if_all_digits(char **arg)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (*(arg + i))
	{
		str = *(arg + i);
		j = 0;
		if (*str == '-' || *str == '+')
			j++;
		if (!(*(str + j)))
			return (0);
		while (*(str + j))
		{
			if (!ft_isdigit(*(str + j)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_for_duplicates(t_slist **top)
{
	t_slist	*current;
	t_slist	*next;

	current = *top;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->data == next->data)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_if_within_int_range(char **arg)
{
	int		i;
	long	num;

	i = 0;
	while (*(arg + i))
	{
		num = ft_atol(*(arg + i));
		if (num > 2147483647 || num < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	eval_args(t_slist **top, char *arg)
{
	char	**arg_split;
	t_slist	*new;
	int		i;
	int		data;

	i = 0;
	arg_split = ft_split(arg, ' ');
	if (!arg_split)
		return (0);
	if (!check_if_all_digits(arg_split) || check_if_within_int_range(arg_split))
		return (free_arg_split(arg_split), 0);
	while (*(i + arg_split))
	{
		data = ft_atoi(*(i + arg_split));
		new = lstnew(data);
		if (!new)
			return (free_arg_split(arg_split), 0);
		if (!(*top))
			*top = new;
		else
			lstadd_back(top, new);
		i++;
	}
	free_arg_split(arg_split);
	return (1);
}
