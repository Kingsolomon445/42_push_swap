/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:19:47 by ofadahun          #+#    #+#             */
/*   Updated: 2023/04/21 12:38:40 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*ft_eval_min_width(const char *format, int *i)
{
	char	*padding;
	char	ch;
	int		min_width_int;

	ch = ' ';
	if (*(format + *i) == '0')
	{
		ch = '0';
		while (*(format + *i) == '0')
			(*i)++;
	}
	if (!ft_isdigit(*(format + *i)))
		return (ft_strdup(""));
	min_width_int = ft_atoi(format + *i);
	padding = malloc(min_width_int + 1);
	if (!padding)
		return (NULL);
	ft_memset(padding, ch, min_width_int);
	padding[min_width_int] = '\0';
	*i += ft_nbrlen(min_width_int, 10);
	return (padding);
}

static char	*ft_handle_flags(const char *format, int *i, char *flag)
{
	char	*padding;

	*flag = '+';
	if (ft_strchr("-", *(format + *i)))
	{
		*flag = '-';
		(*i)++;
		while (*(format + *i) == '0')
			(*i)++;
	}
	if (ft_isdigit(*(format + *i)))
		padding = ft_eval_min_width(format, i);
	else
		padding = ft_strdup("");
	return (padding);
}

int	ft_eval_specifier(const char *format, t_arg *arg, ssize_t *res, int *i)
{
	char	*padding;
	char	flag;

	padding = ft_handle_flags(format, i, &flag);
	if (!padding)
		return (0);
	if (*(format + *i) == 'c')
		ft_printchar(padding, va_arg(arg->args, int), res, flag);
	else if (*(format + *i) == 'i' || *(format + *i) == 'd')
		return (ft_printnbr(padding, va_arg(arg->args, int), res, flag));
	else if (*(format + *i) == 's')
		ft_printstr(padding, va_arg(arg->args, char *), res, flag);
	else if (*(format + *i) == '%')
		ft_printchar(padding, '%', res, flag);
	else if (*(format + *i) == 'u')
		return (ft_printunsignednbr(padding, \
		va_arg(arg->args, unsigned int), res, flag));
	else if (*(format + *i) == 'X')
		return (ft_puhex(padding, va_arg(arg->args, unsigned long), res, flag));
	else if (*(format + *i) == 'x')
		return (ft_plhex(padding, va_arg(arg->args, unsigned int), res, flag));
	else if (*(format + *i) == 'p')
		return (ft_printptr(padding, \
		(unsigned long)va_arg(arg->args, void *), res, flag));
	return (ft_free(padding), 1);
}
