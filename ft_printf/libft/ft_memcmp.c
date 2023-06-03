/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:07:07 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:35:32 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Difference between this and strncmp is that this compares blocks of memory
// i.e bytes while strncmp compares the character one by one.
// So the check doesnt stops at null 
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (n--)
	{
		if (*ptr1 > *ptr2 || *ptr2 > *ptr1)
			return ((unsigned char)*ptr1 - (unsigned char)*ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
