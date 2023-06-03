/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:15:55 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/18 20:19:57 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if ((char)c < 'a' || (char)c > 'z')
		return (0);
	return (1);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c -= ' ';
	return (c);
}
