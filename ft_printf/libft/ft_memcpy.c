/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:20:54 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:35:51 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp;

	if (dst == NULL && src == NULL)
		return (0);
	tmp = (char *)dst;
	while (n--)
	{
		*((char *)dst) = *((char *)src);
		dst++;
		src++;
	}
	return ((void *)tmp);
}
