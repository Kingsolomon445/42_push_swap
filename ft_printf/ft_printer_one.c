/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:20:15 by ofadahun          #+#    #+#             */
/*   Updated: 2023/04/21 12:38:44 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char *padding, int ch, ssize_t *res, char flag)
{
	if (flag == '+')
	{
		if (ft_strlen(padding) > 1)
			ft_putstr_fd(padding + 1, 1);
	}
	ft_putchar_fd(ch, 1);
	if (flag == '-')
	{
		if (ft_strlen(padding) > 1)
			ft_putstr_fd(padding + 1, 1);
	}
	*res += ft_max(ft_strlen(padding), 1);
}

int	ft_printnbr(char *padding, int n, ssize_t *res, char flag)
{
	char	*nbr;
	char	*nbr_to_print;

	nbr = ft_itoa(n);
	if (!nbr)
		return (0);
	nbr_to_print = nbr;
	if (*nbr == '-')
	{
		ft_putchar_fd('-', 1);
		nbr_to_print++;
	}
	if (flag == '+')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	ft_putstr_fd(nbr_to_print, 1);
	if (flag == '-')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	*res += ft_max(ft_strlen(padding), ft_strlen(nbr));
	return (ft_free(nbr), ft_free(padding), 1);
}

void	ft_printstr(char *padding, char *s, ssize_t *res, char flag)
{
	int	len;

	if (!s)
	{
		*res += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(s);
	if (flag == '+')
	{
		if (ft_strlen(padding) > len)
			ft_putstr_fd(padding + len, 1);
	}
	write(1, s, len);
	if (flag == '-')
	{
		if (ft_strlen(padding) > len)
			ft_putstr_fd(padding + len, 1);
	}
	if (ft_strlen(padding) > len)
		*res += ft_strlen(padding);
	else
		*res += len;
}
