/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:08:32 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 21:12:19 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_all(const char *haystack, const char *needle, int len)
{
	while (*haystack && *haystack == *needle && len--)
	{
		if (!(*(needle + 1))) // if the next ch is null, then we have found our substring
			return (1);
		haystack++;
		needle++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*res;
	char		*needletmp;
	size_t		lentmp;

	if (!(*needle) || haystack == needle)
		return ((char *)haystack);
	needletmp = (char *)needle;
	while (len-- && *haystack && *needle)
	{
		if (*haystack == *needle)
		{
			res = (char *)haystack;
			lentmp = len + 1; // This is necessaary so that the len given can still be checked inside the second while loop
			if (check_all(haystack, needle,  lentmp))
				return (res);
			haystack = (const char *)res;//returns back to position before second while loop
			needle = (const char *)needletmp;//return back to the starting position
		}
		haystack++;
	}
	return (0);
}
