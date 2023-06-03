/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:49:07 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/18 20:18:45 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += ' ';
	return (c);
}
