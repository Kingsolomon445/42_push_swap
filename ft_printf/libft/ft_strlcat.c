/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:07:57 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:54:01 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns length of original dest and src string
// the size of the supposed end dst string should be the dstsize , 
// dstsize is the maximum length of the resulting dst string
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		res;

	dstlen = ft_strlen (dst);
	dst += dstlen;//set the pointer to the end of destination string.
	if (dstsize > dstlen)
		res = ft_strlen (src) + dstlen;
	else
		res = ft_strlen(src) + dstsize;
	if (dstsize != 0)
	{
		while (++dstlen < dstsize && *src)
		{
			*dst++ = *src++;
		}
		*dst = '\0';
	}
	return (res);
}
