/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:14:35 by ofadahun          #+#    #+#             */
/*   Updated: 2023/03/16 15:14:48 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//fd(file descriptor) 0-stdin 1-stdout 2-stderr 3-user_defined
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
