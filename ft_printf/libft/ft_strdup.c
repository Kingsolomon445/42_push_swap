/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:51:19 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:49:09 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*res;
	int		s1len;

	s1len = ft_strlen(s1);
	str = (char *)malloc((s1len + 1) * sizeof(char));
	res = str;
	if (str)
	{
		while (*s1)
		{
			*str++ = *s1++;
		}
		*str = '\0';
	}
	return (res);
}
