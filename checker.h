/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:03:58 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 15:05:54 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif //BUFFER_SIZE

# include "push_swap.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

int		ft_strcmp(const char *s1, const char *s2);
char	*free_str(char *str);
char	*ft_modstrjoin(char *old_str, char *move);
int		are_moves_valid(char **moves);

#endif //CHECKER_H