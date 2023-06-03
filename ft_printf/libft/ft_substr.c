/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:37:02 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/23 15:27:00 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*res;
	char	*endptr;
	char	*tmp;
	size_t	size;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s);
	// avoiding memory probelms as a result of too much len than needed or 
	// than len of string passed as argument
	if (len > size)
		len = size;
	//Getting a pointer to the end of the string
	endptr = (char *)s;
	while (*endptr)
		endptr++;
	tmp = (char *)s;
	tmp += start;

	// The purpose of this to check against whne the len given is actually more than what is needed to allocate
	if ((size_t)(endptr - tmp) < len)
		str = (char *)malloc(((endptr - tmp) + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	res = str;
	if (str != NULL)
	{
		while (len-- && *tmp)
			*str++ = *tmp++;
		*str = '\0';
	}
	return (res);
}
