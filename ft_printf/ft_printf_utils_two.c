/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:52:41 by ofadahun          #+#    #+#             */
/*   Updated: 2023/04/21 12:38:57 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(unsigned long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

char	*ft_itoa_lowerhex(unsigned long n)
{
	int		len;
	char	*str;

	len = ft_nbrlen(n, 16);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	while (len--)
	{
		if (n % 16 <= 9)
			*(str + len) = n % 16 + '0';
		else
			*(str + len) = n % 16 + 87;
		n /= 16;
	}
	return (str);
}

char	*ft_itoa_upperhex(unsigned long n)
{
	int		len;
	char	*str;

	len = ft_nbrlen(n, 16);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	while (len--)
	{
		if (n % 16 <= 9)
			*(str + len) = n % 16 + '0';
		else
			*(str + len) = n % 16 + 55;
		n /= 16;
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_nbrlen(n, 10);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	while (len--)
	{
		*(str + len) = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
