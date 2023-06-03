/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:50:51 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 21:29:11 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is present amongst the set
static	int	is_present(char c, char const *set)
{
	char	*ptr;

	ptr = (char *)set;
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

//Iterate through the charcters in set at the beginning of string
//and get the first pointer to char that is not in set 
static char	*get_first_position(char const *str, char const *set)
{
	char	*startptr;

	startptr = (char *)str;
	while (is_present(*startptr, set))
	{
		startptr++;
		if (*startptr == '\0')
			return (0);
	}
	return (startptr);
}

//Get the pointer to last character in string that is not amongst the set
static char	*get_last_position(char const *str, char const *set)
{
	char	*endptr;

	// Setting pointer to the last position of the string
	endptr = (char *)str + (ft_strlen((char *)str) - 1);
	while (is_present(*endptr, set))
	{
		endptr--;
		if (*endptr == '\0')
			return (0);
	}
	return (endptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*startptr;
	char	*endptr;
	char	*res;
	char	*resstart;

	if (!(*s1) || !s1 || !set)
		return (ft_strdup((char *)s1));
	startptr = get_first_position(s1, set);
	endptr = get_last_position(s1, set);
	if (!startptr || !endptr) //If there is no character in string that is not present in set
		return (ft_strdup(""));
	res = (char *)malloc((((endptr - startptr) + 1) + 1) * sizeof(char));
	if (!res)
		return (0);
	resstart = res; // pointing restart to the start of res since res will be shifted in the below while loop
	while (*startptr)
	{
		*res++ = *startptr;
		if (startptr == endptr)
			break ;
		startptr++;
	}
	*res = '\0';
	return (resstart);
}
