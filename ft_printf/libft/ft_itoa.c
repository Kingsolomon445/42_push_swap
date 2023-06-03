/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:08:54 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/23 00:11:35 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	char	*startptr;

	nbr = (long)n; //Necessary to handle INT_MIN
	str = (char *)malloc((get_len(nbr) + 1) * sizeof(char));
	if (!str)
		return (0);
	startptr = str; //Keeps the pointer to first position
	str += get_len(nbr);
	*str = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		*startptr = '-';
	}
	if (nbr == 0)
		*startptr = '0';
	while (nbr > 0)
	{
		*(--str) = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (startptr);
}
