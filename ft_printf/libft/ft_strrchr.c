/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:59:00 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 21:16:13 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns pointer to last occurence of c in string
char	*ft_strrchr(const char *s, int c)
{
	char	*chptr;

	chptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			chptr = (char *) s;
		}
		s++;
	}
	// It can also be a null hence the if
	if (*s == (char)c)
		chptr = (char *) s;
	return ((chptr));
}
