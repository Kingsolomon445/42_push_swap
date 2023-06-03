/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:14:56 by ofadahun          #+#    #+#             */
/*   Updated: 2023/04/21 12:39:03 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_arg	*arg;
	int		i;
	ssize_t	res;

	arg = malloc(sizeof(t_arg));
	if (!arg || !format)
		return (ft_free(arg), -1);
	if (!*format)
		return (ft_free(arg), 0);
	va_start(arg->args, format);
	i = -1;
	res = 0;
	while (++i < ft_strlen(format))
	{
		if (*(format + i) == '%')
		{
			i++;
			if (!ft_eval_specifier(format, arg, &res, &i))
				return (free(arg), -1);
		}
		else
			res += write(1, (format + i), 1);
	}
	return (va_end(arg->args), free(arg), (int)res);
}
