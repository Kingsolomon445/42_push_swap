/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:48:36 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 15:03:49 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((*(s1 + i) && *(s2 + i)))
	{
		if (*(s1 + i) > *(s2 + i) || *(s2 + i) > *(s1 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		i++;
	}
	if (!(*(s1 + i)) && !(*(s2 + i)))
		return (0);
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

char	*free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*ft_modstrjoin(char *old_str, char *move)
{
	char	*new_str;

	if (!old_str)
	{
		old_str = malloc(1);
		if (!old_str)
			return (NULL);
		*old_str = '\0';
	}
	new_str = (char *)malloc(((ft_strlen(move) + ft_strlen(old_str) + 1)) \
	* sizeof(char));
	if (new_str)
	{
		ft_strlcpy(new_str, old_str, ft_strlen(old_str) + 1);
		ft_strlcpy(new_str + ft_strlen(old_str), move, ft_strlen(move) + 1);
	}
	old_str = free_str(old_str);
	return (new_str);
}

int	are_moves_valid(char **moves)
{
	int	i;

	i = 0;
	while (*(moves + i))
	{
		if (!ft_strnstr("papbsasbssrarrarbrrbrrrrr", *(moves + i), 26))
			return (0);
		i++;
	}
	return (1);
}
