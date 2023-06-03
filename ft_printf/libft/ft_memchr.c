/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:22:05 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:33:09 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// searches for the first occurrence of the character c (an unsigned char) 
// in the first n bytes of the string pointed to, by the argument str.
// we need to explicitly cast the ch to unsigned char
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*res;
	unsigned char	ch;

	res = NULL;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*(unsigned char *)s == ch)
		{
			res = (char *)s;
			break ;
		}
		s++;
	}
	return ((void *)res);
}
