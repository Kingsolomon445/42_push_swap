/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:03:15 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:57:03 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	char				*res;
	char				*tmp;
	int					slen;
	unsigned int		i;

	i = 0;
	slen = ft_strlen(s);
	str = (char *)malloc((slen + 1) * sizeof(char));
	tmp = (char *)s;
	res = str;
	if (str != NULL)
	{
		while (*tmp)
		{
			*str++ = f(i, *tmp);
			tmp++;
			i++;
		}
		*str = '\0';
	}
	return (res);
}
