/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:04:09 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/22 20:09:06 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	void	*res;
	size_t	full_size;
	// Avoid buffer overflow, checking for cases when size given is more than
	// the max size that can be allocated
	if (size != 0 && SIZE_MAX / size < count)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	res = ptr;
	full_size = count * size;
	while ((full_size)--)
		*(unsigned char *)ptr++ = 0;
	return (res);
}
