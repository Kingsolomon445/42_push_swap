/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:22:31 by ofadahun          #+#    #+#             */
/*   Updated: 2023/04/21 12:38:49 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsignednbr(char *padding, unsigned int n, \
ssize_t *res, char flag)
{
	char	*nbr;

	nbr = ft_itoa_unsigned(n);
	if (!nbr)
		return (0);
	if (flag == '+')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	ft_putstr_fd(nbr, 1);
	if (flag == '-')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	*res += ft_max(ft_strlen(padding), ft_strlen(nbr));
	return (ft_free(nbr), ft_free(padding), 1);
}

int	ft_plhex(char *padding, unsigned int n, \
ssize_t *res, char flag)
{
	char	*nbr;

	nbr = ft_itoa_lowerhex(n);
	if (!nbr)
		return (0);
	if (flag == '+')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	ft_putstr_fd(nbr, 1);
	if (flag == '-')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	*res += ft_max(ft_strlen(padding), ft_strlen(nbr));
	return (ft_free(nbr), ft_free(padding), 1);
}

int	ft_puhex(char *padding, unsigned int n, \
ssize_t *res, char flag)
{
	char	*nbr;

	nbr = ft_itoa_upperhex(n);
	if (!nbr)
		return (0);
	if (flag == '+')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	ft_putstr_fd(nbr, 1);
	if (flag == '-')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr), 1);
	}
	*res += ft_max(ft_strlen(padding), ft_strlen(nbr));
	return (ft_free(nbr), ft_free(padding), 1);
}

int	ft_printptr(char *padding, unsigned long n, ssize_t *res, char flag)
{
	char	*nbr;

	nbr = ft_itoa_lowerhex(n);
	if (!nbr)
		return (0);
	if (flag == '+')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr) + 2, 1);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(nbr, 1);
	if (flag == '-')
	{
		if (ft_strlen(padding) > ft_strlen(nbr))
			ft_putstr_fd(padding + ft_strlen(nbr) + 2, 1);
	}
	*res += ft_max(ft_strlen(padding), ft_strlen(nbr) + 2);
	return (ft_free(nbr), ft_free(padding), 1);
}
