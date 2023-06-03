/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:16:44 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:39:08 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Difference betqween meemcpy and memmove is that memove allows for overlapping
// such that if yopu have a string "I love you very much" 
// you could do memmove(str+8, str+5, 10)
// It means you are copying string from 'e' and then adding to string 
// starting at 'o' 
// however you cant do this wih memcpy
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dsttmp;
	char	*srctmp;

	if (dst == NULL && src == NULL)
		return (NULL);
	dsttmp = (char *)dst;
	srctmp = (char *)src;
	//If dst pointer comes before src pointer
	if (dsttmp < srctmp)
	{
		while (len--)
			*((char *)dst++) = *((char *)src++);
	}
	else
	{
		dst += len;
		src += len;
		while (len--)
		{
			--dst;
			--src;
			*((char *)dst) = *((char *)src);
		}
	}
	return (dsttmp);
}
