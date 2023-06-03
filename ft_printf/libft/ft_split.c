/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:59:51 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/23 16:01:25 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_count(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while ((*(++s) != c) && *s)
				;
		}
		else
		{
			s++;
		}
	}
	return (count);
}

static int	memory_allocation(char **res, char *start, \
int letter_count, int word_index)
{
	int	sucess;

	sucess = 0;
	// Allocate memory for each column
	*(res + word_index) = (char *)malloc((letter_count + 1) * sizeof(char));
	// Free all the memory already alloctaed if any of the allocation fails
	if (!(*(res + word_index)))
	{
		word_index--;
		while (word_index + 1)
		{
			free(*(res + word_index));
			*(res + word_index) = NULL;
			word_index--;
		}
		free(res);
		res = NULL;
		return (sucess);
	}
	ft_strlcpy(*(res + word_index), start, letter_count + 1);
	sucess++;
	return (sucess);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**res;
	char	*start;
	int		letter_count;
	int		word_index;

	if (!s)
		return (0);
	str = (char *)s;
	word_index = 0;
	// Allocate memory for rows including null
	res = (char **)malloc((get_word_count(str, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*str)
	{
		letter_count = 0;
		start = str;
		// Get length of each valid word
		while (*str != c && *str)
		{
			letter_count++;
			str++;
		}
		if (letter_count > 0)
		{
			if (!(memory_allocation(res, start, letter_count, word_index)))
				return (NULL);
			word_index++;
		}
		if (*str)
			str++;
	}
	*(res + word_index) = NULL;
	return (res);
}
